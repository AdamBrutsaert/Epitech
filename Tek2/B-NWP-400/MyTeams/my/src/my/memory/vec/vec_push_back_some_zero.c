/*
** EPITECH PROJECT, 2024
** vec_push_back_some_zero.c
** File description:
** vec_push_back_some_zero.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_push_back_some_zero(vec_t *self, size_t count)
{
    vec_reserve_at_least(self, self->length + count);
    memset(
        self->data + self->length * self->stride,
        0,
        count * self->stride
    );
    self->length += count;
}
