/*
** EPITECH PROJECT, 2023
** vec_push.c
** File description:
** vec_push.c
*/

#include "my/vector_impl.h"
#include "my/memory.h"

void vec_push(vec_t *vec, const void *data)
{
    if (vec->length == vec->capacity) {
        vec->capacity = vec->capacity * 2 + !vec->capacity;
        vec->data = my_realloc(vec->data, vec->capacity * vec->stride);
    }
    my_memcpy(vec->data + vec->length * vec->stride, data, vec->stride);
    vec->length++;
}
