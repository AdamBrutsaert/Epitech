/*
** EPITECH PROJECT, 2022
** matrix_2d_reflect.c
** File description:
** matrix_2d_reflect.c
*/

#include "matrix.h"

void matrix_2d_reflect(matrix_t *point, float angle)
{
    matrix_t *reflection;
    matrix_t *result;

    if (point->lines != 3 || point->columns != 1)
        return;
    reflection = matrix_create_2d_reflection(angle);
    result = matrix_mul(reflection, point);
    matrix_destroy(reflection);
    matrix_move(point, result);
}
