/*
** EPITECH PROJECT, 2023
** vec_set.c
** File description:
** vec_set.c
*/

#include "my/vector_impl.h"

#include <string.h>

bool vec_set(vec_t *vec, size_t index, const void *data)
{
    if (index >= vec->length)
        return false;
    memcpy(vec->data + index * vec->stride, data, vec->stride);
    return true;
}
