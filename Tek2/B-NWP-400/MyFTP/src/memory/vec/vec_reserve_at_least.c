/*
** EPITECH PROJECT, 2024
** vec_reserve_at_least.c
** File description:
** vec_reserve_at_least.c
*/

#include "memory/vec.h"

bool vec_reserve_at_least(vec_t *self, size_t capacity)
{
    size_t new_capacity = 1;

    if (capacity <= self->capacity)
        return true;
    while (new_capacity <= capacity)
        new_capacity *= 2;
    return vec_reserve(self, new_capacity);
}
