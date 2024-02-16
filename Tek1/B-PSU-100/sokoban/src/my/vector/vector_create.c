/*
** EPITECH PROJECT, 2022
** vector_create.c
** File description:
** vector_create.c
*/

#include "my/vector.h"

void vector_create(vector_t *vector, u64_t stride)
{
    vector->capacity = 0;
    vector->length = 0;
    vector->stride = stride;
    vector->values = nullptr;
}
