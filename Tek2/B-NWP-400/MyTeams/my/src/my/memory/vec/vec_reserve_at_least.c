/*
** EPITECH PROJECT, 2024
** vec_reserve_at_least.c
** File description:
** vec_reserve_at_least.c
*/

#include "my/memory/vec.h"

void vec_reserve_at_least(vec_t *self, size_t capacity)
{
    size_t new_capacity = 1;

    if (capacity <= self->capacity)
        return;
    while (new_capacity <= capacity)
        new_capacity *= 2;
    vec_reserve(self, new_capacity);
}
