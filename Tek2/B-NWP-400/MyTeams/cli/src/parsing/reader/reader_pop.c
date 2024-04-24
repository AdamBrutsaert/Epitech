/*
** EPITECH PROJECT, 2024
** reader_pop.c
** File description:
** reader_pop.c
*/

#include "parsing/reader.h"

char reader_pop(reader_t *self)
{
    if (self->cursor >= VEC_LEN(self->buffer))
        return '\0';
    self->cursor++;
    return *(char *)VEC_AT(self->buffer, self->cursor - 1);
}
