/*
** EPITECH PROJECT, 2024
** vec_reserve.c
** File description:
** vec_reserve.c
*/

#include "my/memory/vec.h"
#include "my/memory/allocation.h"

void vec_reserve(vec_t *self, size_t capacity)
{
    if (capacity <= self->capacity)
        return;
    self->data = reallocate(self->data, capacity * self->stride);
    self->capacity = capacity;
}
