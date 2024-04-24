/*
** EPITECH PROJECT, 2024
** reader_destroy.c
** File description:
** reader_destroy.c
*/

#include "parsing/reader.h"

#include "my/memory/allocation.h"

void reader_destroy(reader_t *self)
{
    vec_destroy(self->buffer);
    deallocate(self);
}
