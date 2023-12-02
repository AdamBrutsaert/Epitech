/*
** EPITECH PROJECT, 2022
** matrix_create_2d_rotation.c
** File description:
** matrix_create_2d_rotation.c
*/

#include "matrix.h"
#include <math.h>

static const float PI = 3.14159265358979323846264338327950288419716939937f;

matrix_t *matrix_create_2d_rotation(float angle)
{
    matrix_t *matrix = matrix_create_identity(3);

    angle *= PI / 180.0f;
    matrix->matrix[0][0] = cos(angle);
    matrix->matrix[0][1] = -sin(angle);
    matrix->matrix[1][0] = sin(angle);
    matrix->matrix[1][1] = cos(angle);
    return matrix;
}
