/*
** EPITECH PROJECT, 2023
** interpreter_process_instruction.c
** File description:
** interpreter_process_instruction.c
*/

#include "shell/interpreter_impl.h"
#include "shell/builtins.h"
#include "shell.h"

#include <unistd.h>

static bool fork_and_execute(interpreter_t *interpreter)
{
    pid_t dummy = 0;
    pid_t *pid;

    if (!VEC_PUSH(interpreter->processes, dummy))
        return false;
    pid = vec_get(interpreter->processes, VEC_LEN(interpreter->processes) - 1);
    *pid = fork();
    if (*pid == -1) {
        vec_pop(interpreter->processes);
        return false;
    }
    if (*pid == 0) {
        interpreter_handle_pipes(interpreter);
        interpreter_execute_program(interpreter);
    }
    return true;
}

static bool execute_builtin(interpreter_t *interpreter)
{
    pid_t dummy = -1;
    int stdout_copy = dup(STDOUT_FILENO);
    int stdin_copy;

    if (!VEC_PUSH(interpreter->processes, dummy) || stdout_copy == -1)
        return false;
    stdin_copy = dup(STDIN_FILENO);
    if (stdin_copy == -1) {
        close(stdout_copy);
        return false;
    }
    interpreter_handle_builtin_pipes(interpreter);
    builtin_execute(interpreter->shell,
        instruction_get_arguments(interpreter->instruction));
    dup2(stdin_copy, STDIN_FILENO);
    dup2(stdout_copy, STDOUT_FILENO);
    close(stdin_copy);
    close(stdout_copy);
    return true;
}

bool interpreter_process_instruction(interpreter_t *interpreter)
{
    bool status;

    if (!interpreter_handle_redirections(interpreter)) {
        shell_set_status(interpreter->shell, 1);
        interpreter_remove_redirections(interpreter);
        return false;
    }
    shell_process_alias(interpreter->shell, interpreter->instruction);
    interpreter_create_pipe(interpreter);
    if (is_builtin(instruction_get_arguments(interpreter->instruction)[0])) {
        status = execute_builtin(interpreter);
    } else {
        status = fork_and_execute(interpreter);
    }
    interpreter_close_pipe(interpreter);
    interpreter_remove_redirections(interpreter);
    return status;
}
