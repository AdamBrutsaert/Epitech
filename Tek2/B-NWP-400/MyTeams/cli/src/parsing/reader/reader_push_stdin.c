/*
** EPITECH PROJECT, 2024
** reader_push_stdin_bytes.c
** File description:
** reader_push_stdin_bytes.c
*/

#include "parsing/reader.h"

#include <unistd.h>

bool reader_push_stdin(reader_t *self)
{
    char buffer[1024];
    ssize_t bytes = read(STDIN_FILENO, buffer, 1024);

    if (bytes <= 0)
        return false;
    vec_push_back_some(
        self->buffer,
        buffer,
        bytes
    );
    return true;
}
