/*
** EPITECH PROJECT, 2022
** matrix_create_identity.c
** File description:
** matrix_create_identity.c
*/

#include "matrix.h"

matrix_t *matrix_create_identity(uint32_t size)
{
    matrix_t *matrix = matrix_create(size, size);

    for (uint32_t i = 0; i < size; i++)
        matrix->matrix[i][i] = 1;
    return matrix;
}
