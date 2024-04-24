/*
** EPITECH PROJECT, 2024
** vec_insert.c
** File description:
** vec_insert.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_insert(vec_t *self, size_t index, const void *value)
{
    vec_reserve_at_least(self, self->length + 1);
    if (index > self->length)
        index = self->length;
    memmove(
        self->data + self->stride * (index + 1),
        self->data + self->stride * index,
        (self->length - index) * self->stride
    );
    memcpy(self->data + self->stride * index, value, self->stride);
    self->length++;
}
