/*
** EPITECH PROJECT, 2023
** vec_new.c
** File description:
** vec_new.c
*/

#include "my/vector_impl.h"
#include "my/memory.h"

vec_t *vec_new(size_t stride)
{
    vec_t *vec = my_calloc(sizeof(vec_t));

    vec->stride = stride;
    return vec;
}
