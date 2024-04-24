/*
** EPITECH PROJECT, 2024
** vec_pop_some_back.c
** File description:
** vec_pop_some_back.c
*/

#include "my/memory/vec.h"

void vec_pop_some_back(vec_t *self, size_t count)
{
    self->length -= count > self->length
        ? self->length
        : count;
}
