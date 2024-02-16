/*
** EPITECH PROJECT, 2022
** vector_create.c
** File description:
** vector_create.c
*/

#include "my/vector.h"

void vector_create(vector_t *vector, u64_t stride)
{
    vector->values = nullptr;
    vector->stride = stride;
    vector->length = 0;
    vector->capacity = 0;
}
