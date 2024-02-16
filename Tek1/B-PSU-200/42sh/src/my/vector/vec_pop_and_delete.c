/*
** EPITECH PROJECT, 2023
** vec_pop_and_delete.c
** File description:
** vec_pop_and_delete.c
*/

#include "my/vector_impl.h"

void vec_pop_and_delete(vec_t *vec, deleter_t deleter)
{
    if (vec->length == 0)
        return;
    (*deleter)(VEC_GET(vec, vec->length - 1, void *));
    vec->length--;
}
