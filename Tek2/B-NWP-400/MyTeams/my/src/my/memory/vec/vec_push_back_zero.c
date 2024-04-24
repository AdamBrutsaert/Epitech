/*
** EPITECH PROJECT, 2024
** vec_push_back_zero.c
** File description:
** vec_push_back_zero.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_push_back_zero(vec_t *self)
{
    vec_reserve_at_least(self, self->length + 1);
    memset(self->data + self->length * self->stride, 0, self->stride);
    self->length++;
}
