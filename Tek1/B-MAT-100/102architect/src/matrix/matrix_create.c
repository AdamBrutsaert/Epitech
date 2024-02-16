/*
** EPITECH PROJECT, 2022
** matrix_create.c
** File description:
** matrix_create.c
*/

#include "matrix.h"
#include <stdlib.h>

matrix_t *matrix_create(uint32_t lines, uint32_t columns)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));

    matrix->lines = lines;
    matrix->columns = columns;
    matrix->matrix = malloc(lines * sizeof(float *));
    for (uint32_t i = 0; i < lines; i++)
        matrix->matrix[i] = malloc(columns * sizeof(float));
    for (uint32_t i = 0; i < lines; i++)
        for (uint32_t j = 0; j < columns; j++)
            matrix->matrix[i][j] = 0.0f;
    return matrix;
}
