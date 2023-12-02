/*
** EPITECH PROJECT, 2023
** vec_delete.c
** File description:
** vec_delete.c
*/

#include "my/vector_impl.h"

#include <stdlib.h>

void vec_delete(vec_t *vec)
{
    if (vec == NULL)
        return;
    free(vec->data);
    free(vec);
}
