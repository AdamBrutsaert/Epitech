/*
** EPITECH PROJECT, 2023
** vec_push.c
** File description:
** vec_push.c
*/

#include "my/vector_impl.h"

#include <stdlib.h>
#include <string.h>

static bool grow(vec_t *vec)
{
    size_t capacity = vec->capacity * 2 + !vec->capacity;
    void *data = realloc(vec->data, capacity * vec->stride);

    if (data == NULL)
        return false;
    vec->data = data;
    vec->capacity = capacity;
    return true;
}

bool vec_push(vec_t *vec, const void *data)
{
    if (vec->length == vec->capacity && !grow(vec))
        return false;
    memcpy(vec->data + vec->length * vec->stride, data, vec->stride);
    vec->length++;
    return true;
}
