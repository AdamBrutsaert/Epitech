/*
** EPITECH PROJECT, 2024
** vec_deinit.c
** File description:
** vec_deinit.c
*/

#include "my/memory/vec.h"
#include "my/memory/allocation.h"

void vec_destroy(vec_t *self)
{
    deallocate(self->data);
    deallocate(self);
}
