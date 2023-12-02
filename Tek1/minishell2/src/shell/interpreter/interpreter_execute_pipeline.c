/*
** EPITECH PROJECT, 2023
** interpreter_execute_pipeline.c
** File description:
** interpreter_execute_pipeline.c
*/

#include "shell/interpreter.h"

#include <sys/wait.h>
#include <unistd.h>

static bool create_pipes(pipeline_t *pipeline)
{
    for (size_t i = 0; i < pipeline->length; i++)
        if (pipe(pipeline->instructions[i]->pipefd) == -1)
            return false;
    return true;
}

static void close_pipes(pipeline_t *pipeline)
{
    for (size_t i = 0; i < pipeline->length; i++) {
        if (pipeline->instructions[i]->pipefd[0] != -1)
            close(pipeline->instructions[i]->pipefd[0]);
        if (pipeline->instructions[i]->pipefd[1] != -1)
            close(pipeline->instructions[i]->pipefd[1]);
    }
}

static bool wait_processes(pipeline_t *pipeline, int *status)
{
    bool has_status = false;

    for (size_t i = 0; i < pipeline->length; i++) {
        if (pipeline->instructions[i]->pid != -1) {
            waitpid(pipeline->instructions[i]->pid, status, 0);
            has_status = true;
        }
    }
    return has_status;
}

void interpreter_execute_pipeline(
    interpreter_t *interpreter,
    pipeline_t *pipeline
)
{
    int status;
    bool error = false;

    if (pipeline_is_empty(pipeline))
        return;
    if (!create_pipes(pipeline)) {
        close_pipes(pipeline);
        return;
    }
    for (size_t i = 0; i < pipeline->length; i++) {
        if (!interpreter_execute_instruction(interpreter, pipeline, i))
            error = true;
    }
    close_pipes(pipeline);
    if (wait_processes(pipeline, &status) && !error) {
        interpreter_process_status(interpreter, status);
    }
}
