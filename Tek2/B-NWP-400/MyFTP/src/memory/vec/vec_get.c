/*
** EPITECH PROJECT, 2024
** vec_get.c
** File description:
** vec_get.c
*/

#include "memory/vec.h"

void *vec_get(vec_t *self, size_t index)
{
    return index >= self->length
        ? NULL
        : self->data + index * self->stride;
}
