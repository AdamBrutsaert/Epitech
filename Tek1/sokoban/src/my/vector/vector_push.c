/*
** EPITECH PROJECT, 2022
** vector_push.c
** File description:
** vector_push.c
*/

#include "my/vector.h"
#include "my/memory.h"

status_t vector_push(vector_t *vector, void *value)
{
    void *ptr;

    if (vector->length == vector->capacity) {
        vector->capacity = vector->capacity * 2 + !vector->capacity;
        ptr = my_realloc(vector->values, vector->capacity * vector->stride);
        if (!ptr)
            return 84;
        vector->values = ptr;
    }
    my_memcpy((i8_t *)vector->values + vector->length * vector->stride,
        value, vector->stride);
    vector->length++;
    return 0;
}
