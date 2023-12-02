/*
** EPITECH PROJECT, 2022
** vector_push.c
** File description:
** vector_push.c
*/

#include "my/vector/internal/vector.h"

#include <my/memory.h>

void vector_push(vector_t *vector, void *value)
{
    if (vector->length == vector->capacity) {
        vector_reserve(vector, vector->capacity * 2 + !vector->capacity);
        if (vector->length == vector->capacity)
            return;
    }

    my_memcpy((int8_t *)vector->data + vector->length * vector->stride, value,
        vector->stride);
    vector->length++;
}
