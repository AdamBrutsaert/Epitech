/*
** EPITECH PROJECT, 2022
** transformation_vector_create.c
** File description:
** transformation_vector_create.c
*/

#include "transformation.h"
#include <stdlib.h>

transformation_vector_t *transformation_vector_create(void)
{
    transformation_vector_t *vector = malloc(sizeof(transformation_vector_t));

    vector->length = 0;
    vector->capacity = 0;
    vector->transformations = NULL;
    return vector;
}
