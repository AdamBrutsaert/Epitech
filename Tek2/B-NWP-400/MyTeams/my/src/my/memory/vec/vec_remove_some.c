/*
** EPITECH PROJECT, 2024
** vec_remove_some.c
** File description:
** vec_remove_some.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_remove_some(vec_t *self, size_t index, size_t count)
{
    if (index >= self->length)
        return;
    if (index + count > self->length)
        count = self->length - index;
    memmove(VEC_AT(self, index), VEC_AT(self, index + count),
        (self->length - index - count) * self->stride);
    self->length -= count;
}
