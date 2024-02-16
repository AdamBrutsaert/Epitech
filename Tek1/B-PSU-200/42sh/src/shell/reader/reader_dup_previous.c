/*
** EPITECH PROJECT, 2023
** reader_dup_previous.c
** File description:
** reader_dup_previous.c
*/

#include "shell/reader_impl.h"

#include <string.h>

char *reader_dup_previous(reader_t *reader, size_t n)
{
    if (reader->cursor < n)
        return NULL;
    return strndup(reader->buffer + reader->cursor - n, n);
}
