/*
** EPITECH PROJECT, 2023
** interpreter_execute_instruction.c
** File description:
** interpreter_execute_instruction.c
*/

#include "shell/interpreter.h"
#include "shell/builtins.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static bool fork_and_execute(
    interpreter_t *interpreter,
    pipeline_t *pipeline,
    size_t index
)
{
    instruction_t *instruction = pipeline->instructions[index];

    instruction->pid = fork();
    if (instruction->pid == -1)
        return false;
    if (instruction->pid == 0) {
        interpreter_handle_pipes(pipeline, index);
        interpreter_execute_program(interpreter, instruction);
    }
    return true;
}

static bool execute_builtin(
    interpreter_t *interpreter,
    pipeline_t *pipeline,
    size_t index
)
{
    int stdout_copy;
    int stdin_copy;
    instruction_t *instruction = pipeline->instructions[index];

    stdout_copy = dup(STDOUT_FILENO);
    if (stdout_copy == -1)
        return false;
    stdin_copy = dup(STDIN_FILENO);
    if (stdin_copy == -1) {
        close(stdout_copy);
        return false;
    }
    interpreter_handle_builtin_pipes(pipeline, index);
    builtin_execute(interpreter, instruction->arguments);
    dup2(stdin_copy, STDIN_FILENO);
    dup2(stdout_copy, STDOUT_FILENO);
    close(stdout_copy);
    close(stdin_copy);
    return true;
}

bool interpreter_execute_instruction(
    interpreter_t *interpreter,
    pipeline_t *pipeline,
    size_t index
)
{
    bool status = true;

    if (instruction_is_empty(pipeline->instructions[index]))
        return true;
    if (!interpreter_process_redirects(pipeline->instructions[index])) {
        interpreter_set_status(interpreter, 1);
        interpreter_remove_redirects(pipeline->instructions[index]);
        return false;
    }
    if (is_builtin(pipeline->instructions[index]->arguments[0])) {
        status = execute_builtin(interpreter, pipeline, index);
    } else {
        status = fork_and_execute(interpreter, pipeline, index);
    }
    interpreter_remove_redirects(pipeline->instructions[index]);
    return status;
}
