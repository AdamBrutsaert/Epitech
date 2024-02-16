/*
** EPITECH PROJECT, 2023
** matrix_get.c
** File description:
** matrix_get.c
*/

#include "lem_in/matrix_impl.h"

int8_t matrix_get(matrix_t *matrix, size_t row, size_t column)
{
    return matrix->data[row * matrix->size + column];
}
