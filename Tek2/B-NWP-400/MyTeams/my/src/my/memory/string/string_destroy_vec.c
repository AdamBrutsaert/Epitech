/*
** EPITECH PROJECT, 2024
** string_destroy_vec.c
** File description:
** string_destroy_vec.c
*/

#include "my/memory/string.h"

void string_destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        string_destroy(*(string_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}
