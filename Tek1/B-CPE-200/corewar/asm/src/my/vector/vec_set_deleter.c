/*
** EPITECH PROJECT, 2023
** vec_set_deleter.c
** File description:
** vec_set_deleter.c
*/

#include "my/vector_impl.h"

void vec_set_deleter(vec_t *vec, deleter_t deleter)
{
    vec->deleter = deleter;
}
