/*
** EPITECH PROJECT, 2023
** vec_clear.c
** File description:
** vec_clear.c
*/

#include "my/vector_impl.h"

void vec_clear(vec_t *vec)
{
    if (vec->deleter) {
        for (size_t i = 0; i < vec->length; i++)
            (*vec->deleter)(VEC_GET(vec, void *, i));
    }
    vec->length = 0;
}
