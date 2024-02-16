/*
** EPITECH PROJECT, 2023
** reader_peek.c
** File description:
** reader_peek.c
*/

#include "shell/reader_impl.h"

char reader_peek(reader_t *reader, size_t n)
{
    if (reader->cursor + n >= reader->length)
        return '\0';
    return reader->buffer[reader->cursor + n];
}
