/*
** EPITECH PROJECT, 2023
** vec_get.c
** File description:
** vec_get.c
*/

#include "my/vector_impl.h"

void *vec_get(vec_t *vec, size_t index)
{
    if (index >= vec->length)
        return NULL;
    return vec->data + index * vec->stride;
}
