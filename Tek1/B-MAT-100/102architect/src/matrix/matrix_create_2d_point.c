/*
** EPITECH PROJECT, 2022
** matrix_create_2d_point.c
** File description:
** matrix_create_2d_point.c
*/

#include "matrix.h"

matrix_t *matrix_create_2d_point(float x, float y)
{
    matrix_t *matrix = matrix_create(3, 1);

    matrix->matrix[0][0] = x;
    matrix->matrix[1][0] = y;
    matrix->matrix[2][0] = 1;
    return matrix;
}
