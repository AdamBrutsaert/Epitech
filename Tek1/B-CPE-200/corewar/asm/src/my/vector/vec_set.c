/*
** EPITECH PROJECT, 2023
** vec_set.c
** File description:
** vec_set.c
*/

#include "my/vector_impl.h"
#include "my/memory.h"

void vec_set(vec_t *vec, size_t index, const void *data)
{
    if (index >= vec->length)
        return;
    if (vec->deleter)
        (*vec->deleter)(VEC_GET(vec, void *, index));
    my_memcpy(vec->data + index * vec->stride, data, vec->stride);
}
