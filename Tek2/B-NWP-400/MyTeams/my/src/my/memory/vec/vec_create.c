/*
** EPITECH PROJECT, 2024
** vec_init.c
** File description:
** vec_init.c
*/

#include "my/memory/vec.h"
#include "my/memory/allocation.h"

vec_t *vec_create(size_t stride)
{
    vec_t *self = allocate(sizeof(vec_t));

    self->data = NULL;
    self->length = 0;
    self->capacity = 0;
    self->stride = stride;
    return self;
}
