/*
** EPITECH PROJECT, 2022
** matrix_print.c
** File description:
** matrix_print.c
*/

#include "matrix.h"
#include <stdio.h>
#include <math.h>

static void matrix_print_number(matrix_t *matrix, uint32_t i, uint32_t j)
{
    float number = roundf(matrix->matrix[i][j] * 100.0f) / 100.0f;

    if (number > -0.005f && number < 0.005f)
        number = 0.0f;
    if (j == matrix->columns - 1) {
        printf("%.2f", number);
    } else {
        printf("%-8.2f", number);
    }
}

void matrix_print(matrix_t *matrix)
{
    for (uint32_t i = 0; i < matrix->lines; i++) {
        for (uint32_t j = 0; j < matrix->columns; j++)
            matrix_print_number(matrix, i, j);
        printf("\n");
    }
}
