/*
** EPITECH PROJECT, 2024
** vec_clear.c
** File description:
** vec_clear.c
*/

#include "my/memory/vec.h"

void vec_clear(vec_t *self)
{
    self->length = 0;
}
