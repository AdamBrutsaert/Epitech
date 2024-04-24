/*
** EPITECH PROJECT, 2024
** vec_pop_some_front.c
** File description:
** vec_pop_some_front.c
*/

#include "my/memory/vec.h"

#include <string.h>

void vec_pop_some_front(vec_t *self, size_t count)
{
    if (count >= self->length) {
        self->length = 0;
        return;
    }
    self->length -= count;
    memmove(self->data, self->data + self->stride * count,
        self->stride * self->length);
}
