/*
** EPITECH PROJECT, 2022
** vector_top.c
** File description:
** vector_top.c
*/

#include "my/vector/internal/vector.h"

#include <stddef.h>

void *vector_top(vector_t *vector)
{
    if (vector->length == 0)
        return NULL;
    return (int8_t *)vector->data + (vector->length - 1) * vector->stride;
}
