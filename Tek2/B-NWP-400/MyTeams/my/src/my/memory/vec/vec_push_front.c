/*
** EPITECH PROJECT, 2024
** vec_push_front.c
** File description:
** vec_push_front.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_push_front(vec_t *self, const void *value)
{
    vec_reserve_at_least(self, self->length + 1);
    memmove(
        self->data + self->stride,
        self->data,
        self->length * self->stride
    );
    memcpy(self->data, value, self->stride);
    self->length++;
}
