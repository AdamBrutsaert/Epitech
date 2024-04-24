/*
** EPITECH PROJECT, 2024
** vec_pop_front.c
** File description:
** vec_pop_front.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_pop_front(vec_t *self)
{
    if (self->length == 0)
        return;
    self->length--;
    memmove(self->data, self->data + self->stride,
        self->stride * self->length);
}
