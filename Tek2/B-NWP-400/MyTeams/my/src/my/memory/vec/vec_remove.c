/*
** EPITECH PROJECT, 2024
** vec_remove.c
** File description:
** vec_remove.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_remove(vec_t *self, size_t index)
{
    if (index >= self->length)
        return;
    memmove(VEC_AT(self, index), VEC_AT(self, index + 1),
        (self->length - index - 1) * self->stride);
    self->length--;
}
