/*
** EPITECH PROJECT, 2022
** matrix_mul.c
** File description:
** matrix_mul.c
*/

#include "matrix.h"
#include <stdlib.h>

static float mul_line_by_col(matrix_t *matrix, matrix_t *mul, uint32_t line,
    uint32_t column)
{
    float sum = 0.0f;

    for (uint32_t i = 0; i < matrix->columns; i++)
        sum += matrix->matrix[line][i] * mul->matrix[i][column];
    return sum;
}

matrix_t *matrix_mul(matrix_t *matrix, matrix_t *mul)
{
    matrix_t *tmp;

    if (matrix->columns != mul->lines)
        return NULL;
    tmp = matrix_create(matrix->lines, mul->columns);
    for (uint32_t i = 0; i < tmp->lines; i++) {
        for (uint32_t j = 0; j < tmp->columns; j++)
            tmp->matrix[i][j] = mul_line_by_col(matrix, mul, i, j);
    }
    return tmp;
}
