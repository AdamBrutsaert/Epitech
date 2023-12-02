/*
** EPITECH PROJECT, 2022
** vector_set.c
** File description:
** vector_set.c
*/

#include "my/vector/internal/vector.h"

#include <my/memory.h>

void vector_set(vector_t *vector, uint64_t index, void *value)
{
    if (index >= vector->length)
        return;
    my_memcpy((int8_t *)vector->data + index * vector->stride, value,
        vector->stride);
}
