/*
** EPITECH PROJECT, 2022
** vector_get.c
** File description:
** vector_get.c
*/

#include "my/vector/internal/vector.h"

#include <stddef.h>

void *vector_get(vector_t *vector, uint64_t index)
{
    if (index >= vector->length)
        return NULL;
    return (int8_t *)vector->data + vector->stride * index;
}
