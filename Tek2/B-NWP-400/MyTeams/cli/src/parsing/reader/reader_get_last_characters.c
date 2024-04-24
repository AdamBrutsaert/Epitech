/*
** EPITECH PROJECT, 2024
** reader_get_last_characters.c
** File description:
** reader_get_last_characters.c
*/

#include "parsing/reader.h"

string_t *reader_get_last_characters(reader_t *self, size_t n)
{
    if (n > self->cursor)
        n = self->cursor;
    return string_create_from_buffer(
        (char *)VEC_DATA(self->buffer) + self->cursor - n,
        n
    );
}
