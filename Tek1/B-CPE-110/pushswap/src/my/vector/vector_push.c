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
    if (vector->length == vector->capacity) {
        if (vector_reserve(vector,
            vector->capacity * 2 + !vector->capacity) == STATUS_ERROR)
            return STATUS_ERROR;
    }
    my_memcpy((i8_t *)vector->values + vector->length * vector->stride, value,
        vector->stride);
    vector->length++;
    return STATUS_SUCCESS;
}
