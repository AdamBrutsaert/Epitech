/*
** EPITECH PROJECT, 2023
** interpreter_handle_pipes.c
** File description:
** interpreter_handle_pipes.c
*/

#include "shell/interpreter.h"

#include <unistd.h>

void interpreter_handle_pipes(
    pipeline_t *pipeline,
    size_t index
)
{
    for (size_t i = 0; i + 1 < index; i++) {
        close(pipeline->instructions[i]->pipefd[0]);
        close(pipeline->instructions[i]->pipefd[1]);
    }
    for (size_t i = index + 1; i < pipeline->length; i++) {
        close(pipeline->instructions[i]->pipefd[0]);
        close(pipeline->instructions[i]->pipefd[1]);
    }
    if (index != 0) {
        close(pipeline->instructions[index - 1]->pipefd[1]);
        dup2(pipeline->instructions[index - 1]->pipefd[0], STDIN_FILENO);
    }
    if (index + 1 != pipeline->length) {
        close(pipeline->instructions[index]->pipefd[0]);
        dup2(pipeline->instructions[index]->pipefd[1], STDOUT_FILENO);
    } else {
        close(pipeline->instructions[index]->pipefd[0]);
        close(pipeline->instructions[index]->pipefd[1]);
    }
}
