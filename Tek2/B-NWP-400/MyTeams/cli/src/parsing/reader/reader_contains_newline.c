/*
** EPITECH PROJECT, 2024
** reader_contains_newline.c
** File description:
** reader_contains_newline.c
*/

#include "parsing/reader.h"

bool reader_contains_newline(reader_t *self)
{
    for (size_t i = self->cursor; i < VEC_LEN(self->buffer); i++) {
        if (*(char *)VEC_AT(self->buffer, i) == '\n')
            return true;
    }
    return false;
}
