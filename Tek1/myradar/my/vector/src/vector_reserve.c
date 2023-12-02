/*
** EPITECH PROJECT, 2022
** vector_reserve.c
** File description:
** vector_reserve.c
*/

#include "my/vector/internal/vector.h"

#include <my/memory.h>

void vector_reserve(vector_t *vector, uint64_t capacity)
{
    void *ptr;

    if (vector->capacity >= capacity)
        return;
    ptr = my_realloc(vector->data, capacity * vector->stride);
    if (!ptr)
        return;
    vector->data = ptr;
    vector->capacity = capacity;
}
