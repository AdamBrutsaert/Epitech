/*
** EPITECH PROJECT, 2024
** vec_capacity.c
** File description:
** vec_capacity.c
*/

#include "memory/vec.h"

size_t vec_capacity(const vec_t *self)
{
    return self->capacity;
}
