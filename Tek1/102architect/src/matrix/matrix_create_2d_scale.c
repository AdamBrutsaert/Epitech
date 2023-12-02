/*
** EPITECH PROJECT, 2022
** matrix_create_2d_scale.c
** File description:
** matrix_create_2d_scale.c
*/

#include "matrix.h"

matrix_t *matrix_create_2d_scale(float x, float y)
{
    matrix_t *matrix = matrix_create_identity(3);

    matrix->matrix[0][0] = x;
    matrix->matrix[1][1] = y;
    return matrix;
}
