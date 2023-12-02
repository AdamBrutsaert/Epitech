/*
** EPITECH PROJECT, 2022
** matrix_destroy.c
** File description:
** matrix_destroy.c
*/

#include "matrix.h"
#include <stdlib.h>

void matrix_destroy(matrix_t *matrix)
{
    if (!matrix)
        return;
    for (uint32_t i = 0; i < matrix->lines; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}
