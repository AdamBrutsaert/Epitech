/*
** EPITECH PROJECT, 2022
** transformation_vector_destroy.c
** File description:
** transformation_vector_destroy.c
*/

#include "transformation.h"
#include <stdlib.h>

void transformation_vector_destroy(transformation_vector_t *vector)
{
    free(vector->transformations);
    free(vector);
}
