/*
** EPITECH PROJECT, 2023
** vec_delete.c
** File description:
** vec_delete.c
*/

#include "my/vector_impl.h"
#include "my/memory.h"

void vec_delete(vec_t *vec)
{
    vec_clear(vec);
    my_free(vec->data);
    my_free(vec);
}
