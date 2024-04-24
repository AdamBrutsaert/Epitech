/*
** EPITECH PROJECT, 2024
** vec_insert_some.c
** File description:
** vec_insert_some.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_insert_some(
    vec_t *self,
    size_t index,
    const void *values,
    size_t count
)
{
    vec_reserve_at_least(self, self->length + count);
    if (index > self->length)
        index = self->length;
    memmove(
        self->data + self->stride * (index + count),
        self->data + self->stride * index,
        (self->length - index) * self->stride
    );
    memcpy(
        self->data + self->stride * index,
        values,
        count * self->stride
    );
    self->length += count;
}
