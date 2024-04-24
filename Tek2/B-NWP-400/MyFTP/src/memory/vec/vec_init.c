/*
** EPITECH PROJECT, 2024
** vec_init.c
** File description:
** vec_init.c
*/

#include "memory/vec.h"

void vec_init(vec_t *self, size_t stride)
{
    self->data = NULL;
    self->length = 0;
    self->capacity = 0;
    self->stride = stride;
}
