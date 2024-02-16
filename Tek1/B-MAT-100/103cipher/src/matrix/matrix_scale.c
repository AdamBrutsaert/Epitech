/*
** EPITECH PROJECT, 2022
** matrix_scale.c
** File description:
** matrix_scale.c
*/

#include "matrix.h"

matrix_t *matrix_scale(matrix_t *matrix, float factor)
{
    matrix_t *tmp;

    tmp = matrix_create(matrix->lines, matrix->columns);
    for (uint32_t i = 0; i < tmp->lines; i++) {
        for (uint32_t j = 0; j < tmp->columns; j++)
            tmp->matrix[i][j] = factor * matrix->matrix[i][j];
    }
    return tmp;
}
