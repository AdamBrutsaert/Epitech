/*
** EPITECH PROJECT, 2022
** matrix_move.c
** File description:
** matrix_move.c
*/

#include "matrix.h"
#include <stdlib.h>

void matrix_move(matrix_t *matrix, matrix_t *move)
{
    for (uint32_t i = 0; i < matrix->lines; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    matrix->lines = move->lines;
    matrix->columns = move->columns;
    matrix->matrix = move->matrix;
    move->lines = 0;
    move->columns = 0;
    move->matrix = NULL;
    matrix_destroy(move);
}
