/*
** EPITECH PROJECT, 2023
** vec_new.c
** File description:
** vec_new.c
*/

#include "my/vector_impl.h"

#include <stdlib.h>

vec_t *vec_new(size_t stride)
{
    vec_t *vec = calloc(1, sizeof(vec_t));

    if (vec == NULL)
        return NULL;
    vec->stride = stride;
    return vec;
}
