/*
** EPITECH PROJECT, 2023
** interpreter_close_pipe.c
** File description:
** interpreter_close_pipe.c
*/

#include "shell/interpreter_impl.h"

#include <unistd.h>

void interpreter_close_pipe(interpreter_t *interpreter)
{
    size_t index = interpreter->instruction_index;
    int *fd;

    for (size_t i = 0; i < index; i++) {
        fd = vec_get(interpreter->pipes, 2 * i);
        if (*fd != -1) {
            close(*fd);
            *fd = -1;
        }
        fd = vec_get(interpreter->pipes, 2 * i + 1);
        if (*fd != -1) {
            close(*fd);
            *fd = -1;
        }
    }
}
