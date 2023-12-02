/*
** EPITECH PROJECT, 2022
** vector_get.c
** File description:
** vector_get.c
*/

#include "my/vector.h"

void *vector_get(vector_t *vector, u64_t index)
{
    return (i8_t *)vector->values + index * vector->stride;
}
