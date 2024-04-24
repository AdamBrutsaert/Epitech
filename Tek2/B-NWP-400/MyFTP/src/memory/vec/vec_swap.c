/*
** EPITECH PROJECT, 2024
** vec_swap.c
** File description:
** vec_swap.c
*/

#include "memory/vec.h"

bool vec_swap(vec_t *self, size_t index1, size_t index2)
{
    uint8_t byte;
    uint8_t *ptr1 = self->data + index1 * self->stride;
    uint8_t *ptr2 = self->data + index2 * self->stride;

    if (index1 >= self->length || index2 >= self->length)
        return false;
    for (size_t i = 0; i < self->stride; i++) {
        byte = ptr1[i];
        ptr1[i] = ptr2[i];
        ptr2[i] = byte;
    }
    return true;
}
