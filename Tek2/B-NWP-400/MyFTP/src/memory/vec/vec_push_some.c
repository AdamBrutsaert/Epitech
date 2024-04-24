/*
** EPITECH PROJECT, 2024
** vec_push_some.c
** File description:
** vec_push_some.c
*/

#include "memory/vec.h"

#include <string.h>

bool vec_push_some(vec_t *self, const void *values, size_t length)
{
    if (!vec_reserve_at_least(self, self->length + length))
        return false;
    memcpy(self->data + self->length * self->stride, values,
        length * self->stride);
    self->length += length;
    return true;
}
