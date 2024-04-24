/*
** EPITECH PROJECT, 2024
** vec_push.c
** File description:
** vec_push.c
*/

#include "memory/vec.h"

#include <string.h>

bool vec_push(vec_t *self, const void *value)
{
    if (!vec_reserve_at_least(self, self->length + 1))
        return false;
    memcpy(self->data + self->length * self->stride, value, self->stride);
    self->length++;
    return true;
}
