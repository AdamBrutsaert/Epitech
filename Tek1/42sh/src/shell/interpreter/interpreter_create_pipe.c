/*
** EPITECH PROJECT, 2023
** interpreter_create_pipe.c
** File description:
** interpreter_create_pipe.c
*/

#include "shell/interpreter_impl.h"

#include <unistd.h>

void interpreter_create_pipe(interpreter_t *interpreter)
{
    size_t index = interpreter->instruction_index;
    size_t length = VEC_LEN(pipeline_get_instructions(interpreter->pipeline));
    int fd[2];

    if (index + 1 != length) {
        pipe(fd);
        VEC_PUSH(interpreter->pipes, fd[0]);
        VEC_PUSH(interpreter->pipes, fd[1]);
    }
}
