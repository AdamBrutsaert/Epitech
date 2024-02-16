/*
** EPITECH PROJECT, 2023
** vec_clear_and_delete.c
** File description:
** vec_clear_and_delete.c
*/

#include "my/vector_impl.h"

void vec_clear_and_delete(vec_t *vec, deleter_t deleter)
{
    if (vec == NULL)
        return;
    for (size_t i = 0; i < vec->length; i++)
        (*deleter)(VEC_GET(vec, i, void *));
    vec->length = 0;
}
