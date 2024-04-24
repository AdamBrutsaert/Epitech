/*
** EPITECH PROJECT, 2024
** vec_pop_back.c
** File description:
** vec_pop_back.c
*/

#include "my/memory/vec.h"

void vec_pop_back(vec_t *self)
{
    self->length -= !!self->length;
}
