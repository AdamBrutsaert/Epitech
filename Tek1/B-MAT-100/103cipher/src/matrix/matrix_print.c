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
    if (j == matrix->columns - 1) {
        printf("%d", (uint32_t)matrix->matrix[i][j]);
    } else {
        printf("%-8d", (uint32_t)matrix->matrix[i][j]);
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

static void matrix_printf_number(matrix_t *matrix, uint32_t i, uint32_t j)
{
    if (j == matrix->columns - 1) {
        if (matrix->matrix[i][j] > -0.0005 && matrix->matrix[i][j] < 0.0005) {
            printf("0.0");
        } else {
            printf("%.3f", matrix->matrix[i][j]);
        }
    } else {
        if (matrix->matrix[i][j] > -0.0005 && matrix->matrix[i][j] < 0.0005) {
            printf("0.0     ");
        } else {
            printf("%-8.3f", matrix->matrix[i][j]);
        }
    }
}

void matrix_printf(matrix_t *matrix)
{
    for (uint32_t i = 0; i < matrix->lines; i++) {
        for (uint32_t j = 0; j < matrix->columns; j++)
            matrix_printf_number(matrix, i, j);
        printf("\n");
    }
}
