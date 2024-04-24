/*
** EPITECH PROJECT, 2024
** vec_reserve.c
** File description:
** vec_reserve.c
*/

#include "memory/vec.h"

#include <stdlib.h>

bool vec_reserve(vec_t *self, size_t capacity)
{
    void *data;

    if (capacity <= self->capacity)
        return true;
    data = realloc(self->data, capacity * self->stride);
    if (data == NULL)
        return false;
    self->data = data;
    self->capacity = capacity;
    return true;
}
