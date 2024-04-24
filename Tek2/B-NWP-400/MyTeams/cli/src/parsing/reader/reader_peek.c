/*
** EPITECH PROJECT, 2024
** reader_peek.c
** File description:
** reader_peek.c
*/

#include "parsing/reader.h"

char reader_peek(reader_t *self)
{
    if (self->cursor >= VEC_LEN(self->buffer))
        return '\0';
    return *(char *)VEC_AT(self->buffer, self->cursor);
}
