/*
** EPITECH PROJECT, 2022
** matrix.h
** File description:
** matrix.h
*/

#pragma once

#include <stdint.h>

typedef struct {
    uint32_t lines;
    uint32_t columns;
    float **matrix;
} matrix_t;

matrix_t *matrix_create(uint32_t lines, uint32_t columns);
matrix_t *matrix_create_identity(uint32_t size);
void matrix_move(matrix_t *matrix, matrix_t *move);
void matrix_destroy(matrix_t *matrix);

matrix_t *matrix_inverse(matrix_t *matrix);
matrix_t *matrix_scale(matrix_t *matrix, float factor);
matrix_t *matrix_mul(matrix_t *matrix, matrix_t *mul);
void matrix_print(matrix_t *matrix);
void matrix_printf(matrix_t *matrix);
