/*
** EPITECH PROJECT, 2023
** interpreter_handle_builtin_pipes.c
** File description:
** interpreter_handle_builtin_pipes.c
*/

#include "shell/interpreter.h"

#include <unistd.h>

void interpreter_handle_builtin_pipes(
    pipeline_t *pipeline,
    size_t index
)
{
    if (index != 0)
        dup2(pipeline->instructions[index - 1]->pipefd[0], STDIN_FILENO);
    if (index + 1 != pipeline->length)
        dup2(pipeline->instructions[index]->pipefd[1], STDOUT_FILENO);
}
