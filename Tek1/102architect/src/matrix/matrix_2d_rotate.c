/*
** EPITECH PROJECT, 2022
** matrix_2d_rotate.c
** File description:
** matrix_2d_rotate.c
*/

#include "matrix.h"

void matrix_2d_rotate(matrix_t *point, float angle)
{
    matrix_t *rotation;
    matrix_t *result;

    if (point->lines != 3 || point->columns != 1)
        return;
    rotation = matrix_create_2d_rotation(angle);
    result = matrix_mul(rotation, point);
    matrix_destroy(rotation);
    matrix_move(point, result);
}
