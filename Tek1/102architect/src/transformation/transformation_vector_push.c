/*
** EPITECH PROJECT, 2022
** transformation_vector_push.c
** File description:
** transformation_vector_push.c
*/

#include "architect.h"
#include <stdlib.h>

void transformation_vector_push(transformation_vector_t *vector,
    transformation_type_t type, float param1, float param2)
{
    if (vector->length == vector->capacity) {
        vector->capacity = vector->capacity * 2 + !vector->capacity;
        vector->transformations = realloc(vector->transformations,
            vector->capacity * sizeof(transformation_t));
    }
    vector->transformations[vector->length].type = type;
    vector->transformations[vector->length].param1 = param1;
    vector->transformations[vector->length].param2 = param2;
    vector->length++;
}
