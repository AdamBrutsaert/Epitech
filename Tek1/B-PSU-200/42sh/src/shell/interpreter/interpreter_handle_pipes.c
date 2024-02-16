/*
** EPITECH PROJECT, 2023
** interpreter_handle_pipes.c
** File description:
** interpreter_handle_pipes.c
*/

#include "shell/interpreter_impl.h"

#include <unistd.h>

void interpreter_handle_pipes(interpreter_t *interpreter)
{
    size_t index = interpreter->instruction_index;
    size_t length = VEC_LEN(pipeline_get_instructions(interpreter->pipeline));

    if (index != 0) {
        close(VEC_GET(interpreter->pipes, 2 * (index - 1) + 1, int));
        dup2(VEC_GET(interpreter->pipes, 2 * (index - 1), int), STDIN_FILENO);
    }
    if (index + 1 != length) {
        close(VEC_GET(interpreter->pipes, 2 * index, int));
        dup2(VEC_GET(interpreter->pipes, 2 * index + 1, int), STDOUT_FILENO);
    }
}
