/*
** EPITECH PROJECT, 2024
** vec_push_back_some.c
** File description:
** vec_push_back_some.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_push_back_some(vec_t *self, const void *values, size_t count)
{
    vec_reserve_at_least(self, self->length + count);
    memcpy(
        self->data + self->length * self->stride,
        values,
        count * self->stride
    );
    self->length += count;
}
