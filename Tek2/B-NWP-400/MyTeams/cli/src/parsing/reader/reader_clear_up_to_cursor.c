/*
** EPITECH PROJECT, 2024
** reader_clear_up_to_cursor.c
** File description:
** reader_clear_up_to_cursor.c
*/

#include "parsing/reader.h"

void reader_clear_up_to_cursor(reader_t *self)
{
    vec_pop_some_front(self->buffer, self->cursor);
    self->cursor = 0;
}
