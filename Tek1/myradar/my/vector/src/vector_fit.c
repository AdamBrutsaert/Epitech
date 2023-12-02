/*
** EPITECH PROJECT, 2022
** vector_fit.c
** File description:
** vector_fit.c
*/

#include "my/vector/internal/vector.h"

#include <my/memory.h>

void vector_fit(vector_t *vector)
{
    void *ptr;

    if (vector->length == 0) {
        my_free(vector->data);
        vector->data = NULL;
        vector->capacity = vector->length;
        return;
    }
    ptr = my_realloc(vector->data, vector->length * vector->stride);
    if (!ptr)
        return;
    vector->data = ptr;
    vector->capacity = vector->length;
}
