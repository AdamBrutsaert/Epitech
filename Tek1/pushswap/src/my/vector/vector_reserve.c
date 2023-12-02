/*
** EPITECH PROJECT, 2022
** vector_reserve.c
** File description:
** vector_reserve.c
*/

#include "my/vector.h"
#include "my/memory.h"

status_t vector_reserve(vector_t *vector, u64_t capacity)
{
    void *values;

    if (capacity <= vector->capacity)
        return STATUS_ERROR;
    values = my_realloc(vector->values, capacity * vector->stride);
    if (!values)
        return STATUS_ERROR;
    vector->capacity = capacity;
    vector->values = values;
    return STATUS_SUCCESS;
}
