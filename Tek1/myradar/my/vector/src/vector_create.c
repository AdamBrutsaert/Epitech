/*
** EPITECH PROJECT, 2022
** vector_create.c
** File description:
** vector_create.c
*/

#include "my/vector/internal/vector.h"

#include <my/memory.h>

vector_t *vector_create(uint64_t stride)
{
    vector_t *vector = my_malloc(sizeof(vector_t));

    vector->data = NULL;
    vector->stride = stride;
    vector->length = 0;
    vector->capacity = 0;
    return vector;
}
