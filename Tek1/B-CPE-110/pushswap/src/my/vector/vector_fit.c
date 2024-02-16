/*
** EPITECH PROJECT, 2022
** vector_fit.c
** File description:
** vector_fit.c
*/

#include "my/vector.h"
#include "my/memory.h"

status_t vector_fit(vector_t *vector)
{
    void *values;

    values = my_realloc(vector->values, vector->length * vector->stride);
    if (!vector->length && !values)
        return STATUS_ERROR;
    vector->capacity = vector->length;
    vector->values = values;
    return STATUS_SUCCESS;
}
