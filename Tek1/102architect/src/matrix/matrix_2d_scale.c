/*
** EPITECH PROJECT, 2022
** matrix_2d_scale.c
** File description:
** matrix_2d_scale.c
*/

#include "matrix.h"

void matrix_2d_scale(matrix_t *point, float x, float y)
{
    matrix_t *scale;
    matrix_t *result;

    if (point->lines != 3 || point->columns != 1)
        return;
    scale = matrix_create_2d_scale(x, y);
    result = matrix_mul(scale, point);
    matrix_destroy(scale);
    matrix_move(point, result);
}
