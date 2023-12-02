/*
** EPITECH PROJECT, 2023
** vec_pop.c
** File description:
** vec_pop.c
*/

#include "my/vector_impl.h"

void vec_pop(vec_t *vec)
{
    vec->length -= !!vec->length;
}
