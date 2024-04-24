/*
** EPITECH PROJECT, 2024
** vec_deinit.c
** File description:
** vec_deinit.c
*/

#include "memory/vec.h"

#include <stdlib.h>

void vec_deinit(vec_t *self)
{
    free(self->data);
}
