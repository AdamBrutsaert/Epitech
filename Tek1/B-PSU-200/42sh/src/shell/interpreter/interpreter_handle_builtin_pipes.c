/*
** EPITECH PROJECT, 2023
** interpreter_handle_builtin_pipes.c
** File description:
** interpreter_handle_builtin_pipes.c
*/

#include "shell/interpreter_impl.h"

#include <unistd.h>

void interpreter_handle_builtin_pipes(interpreter_t *interpreter)
{
    size_t index = interpreter->instruction_index;
    size_t length = VEC_LEN(pipeline_get_instructions(interpreter->pipeline));

    if (index != 0)
        dup2(VEC_GET(interpreter->pipes, 2 * (index - 1), int), STDIN_FILENO);
    if (index + 1 != length)
        dup2(VEC_GET(interpreter->pipes, 2 * index + 1, int), STDOUT_FILENO);
}
