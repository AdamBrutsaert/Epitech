/*
** EPITECH PROJECT, 2024
** vec_push_back.c
** File description:
** vec_push_back.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_push_back(vec_t *self, const void *value)
{
    vec_reserve_at_least(self, self->length + 1);
    memcpy(self->data + self->length * self->stride, value, self->stride);
    self->length++;
}
