/*
** EPITECH PROJECT, 2022
** matrix_create_2d_translation.c
** File description:
** matrix_create_2d_translation.c
*/

#include "matrix.h"

matrix_t *matrix_create_2d_translation(float x, float y)
{
    matrix_t *matrix = matrix_create_identity(3);

    matrix->matrix[0][2] = x;
    matrix->matrix[1][2] = y;
    return matrix;
}
