/*
** EPITECH PROJECT, 2022
** matrix_2d_translate.c
** File description:
** matrix_2d_translate.c
*/

#include "matrix.h"
#include <stdlib.h>

void matrix_2d_translate(matrix_t *point, float x, float y)
{
    matrix_t *translation;
    matrix_t *result;

    if (point->lines != 3 || point->columns != 1)
        return;
    translation = matrix_create_2d_translation(x, y);
    result = matrix_mul(translation, point);
    matrix_destroy(translation);
    matrix_move(point, result);
}
