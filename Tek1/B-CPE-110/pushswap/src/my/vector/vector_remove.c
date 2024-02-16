/*
** EPITECH PROJECT, 2022
** vector_remove.c
** File description:
** vector_remove.c
*/

#include "my/vector.h"
#include "my/memory.h"

status_t vector_remove(vector_t *vector, u64_t index)
{
    if (index >= vector->length)
        return STATUS_ERROR;
    my_memmove((i8_t *)vector->values + index * vector->stride,
        (i8_t *)vector->values + (index + 1) * vector->stride,
        (vector->length - index - 1) * vector->stride);
    vector->length--;
    return STATUS_SUCCESS;
}
