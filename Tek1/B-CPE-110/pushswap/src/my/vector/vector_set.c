/*
** EPITECH PROJECT, 2022
** vector_set.c
** File description:
** vector_set.c
*/

#include "my/vector.h"
#include "my/memory.h"

status_t vector_set(vector_t *vector, u64_t index, void *value)
{
    if (index >= vector->length)
        return STATUS_ERROR;
    my_memcpy((i8_t *)vector->values + index * vector->stride, value,
        vector->stride);
    return STATUS_SUCCESS;
}
