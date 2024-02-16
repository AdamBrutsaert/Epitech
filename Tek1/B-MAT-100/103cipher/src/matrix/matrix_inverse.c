/*
** EPITECH PROJECT, 2022
** matrix_inverse.c
** File description:
** matrix_inverse.c
*/

#include "matrix.h"
#include <stdlib.h>

static matrix_t *matrix_inverse_1d(matrix_t *matrix)
{
    matrix_t *tmp;

    if (matrix->matrix[0][0] == 0)
        return NULL;
    tmp = matrix_create(1, 1);
    tmp->matrix[0][0] = 1.0f / matrix->matrix[0][0];
    return tmp;
}

static matrix_t *matrix_inverse_2d(matrix_t *matrix)
{
    float det = matrix->matrix[0][0] * matrix->matrix[1][1]
        - matrix->matrix[0][1] * matrix->matrix[1][0];
    matrix_t *tmp;

    if (det == 0)
        return NULL;
    tmp = matrix_create(2, 2);
    tmp->matrix[0][0] = matrix->matrix[1][1];
    tmp->matrix[0][1] = -matrix->matrix[0][1];
    tmp->matrix[1][0] = -matrix->matrix[1][0];
    tmp->matrix[1][1] = matrix->matrix[0][0];
    matrix_move(tmp, matrix_scale(tmp, 1.0f / det));
    return tmp;
}

static matrix_t *matrix_inverse_3d(matrix_t *matrix)
{
    float a = matrix->matrix[0][0];
    float b = matrix->matrix[0][1];
    float c = matrix->matrix[0][2];
    float d = matrix->matrix[1][0];
    float e = matrix->matrix[1][1];
    float f = matrix->matrix[1][2];
    float g = matrix->matrix[2][0];
    float h = matrix->matrix[2][1];
    float i = matrix->matrix[2][2];

    float det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

    if (det == 0.0f)
        return NULL;

    matrix_t *tmp = matrix_create(3, 3);

    tmp->matrix[0][0] = (e * i - f * h);
    tmp->matrix[0][1] = (c * h - b * i);
    tmp->matrix[0][2] = (b * f - c * e);
    tmp->matrix[1][0] = (f * g - d * i);
    tmp->matrix[1][1] = (a * i - c * g);
    tmp->matrix[1][2] = (c * d - a * f);
    tmp->matrix[2][0] = (d * h - e * g);
    tmp->matrix[2][1] = (b * g - a * h);
    tmp->matrix[2][2] = (a * e - b * d);

    matrix_move(tmp, matrix_scale(tmp, 1.0f / det));

    return tmp;
}

matrix_t *matrix_inverse(matrix_t *matrix)
{
    if (matrix->lines == 1 && matrix->columns == 1)
        return matrix_inverse_1d(matrix);
    if (matrix->lines == 2 && matrix->columns == 2)
        return matrix_inverse_2d(matrix);
    if (matrix->lines == 3 && matrix->columns == 3)
        return matrix_inverse_3d(matrix);
    return NULL;
}
