/*
** EPITECH PROJECT, 2023
** reader_next.c
** File description:
** reader_next.c
*/

#include "asm/reader_impl.h"

static char next(reader_t *reader)
{
    if (reader->cursor >= reader->length) {
        reader->cursor = reader->length;
        return '\0';
    }
    if (reader->buffer[reader->cursor] == '\n')
        reader->line++;
    reader->cursor++;
    return reader->buffer[reader->cursor - 1];
}

char reader_next(reader_t *reader, size_t offset)
{
    char character = '\0';

    for (size_t i = 0; i < offset; i++)
        character = next(reader);
    return character;
}
