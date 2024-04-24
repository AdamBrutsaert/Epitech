/*
** EPITECH PROJECT, 2024
** reader_clear_up_to_newline.c
** File description:
** reader_clear_up_to_newline.c
*/

#include "parsing/reader.h"

void reader_clear_up_to_newline(reader_t *self)
{
    size_t index = self->cursor;

    while (index < VEC_LEN(self->buffer) &&
        *(char *)VEC_AT(self->buffer, index) != '\n')
        index++;
    if (index < VEC_LEN(self->buffer))
        index++;
    vec_pop_some_front(self->buffer, index);
    self->cursor = 0;
}
