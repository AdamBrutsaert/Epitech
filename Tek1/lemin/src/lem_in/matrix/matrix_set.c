/*
** EPITECH PROJECT, 2023
** matrix_set.c
** File description:
** matrix_set.c
*/

#include "lem_in/matrix_impl.h"

void matrix_set(matrix_t *matrix, size_t row, size_t column, int8_t value)
{
    matrix->data[row * matrix->size + column] = value;
}
