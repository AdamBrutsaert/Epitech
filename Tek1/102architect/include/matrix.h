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
matrix_t *matrix_create_2d_point(float x, float y);
matrix_t *matrix_create_2d_translation(float x, float y);
matrix_t *matrix_create_2d_scale(float x, float y);
matrix_t *matrix_create_2d_rotation(float angle);
matrix_t *matrix_create_2d_reflection(float angle);
void matrix_move(matrix_t *matrix, matrix_t *move);
void matrix_destroy(matrix_t *matrix);

matrix_t *matrix_mul(matrix_t *matrix, matrix_t *mul);

void matrix_2d_translate(matrix_t *point, float x, float y);
void matrix_2d_scale(matrix_t *point, float x, float y);
void matrix_2d_rotate(matrix_t *point, float angle);
void matrix_2d_reflect(matrix_t *point, float angle);

void matrix_print(matrix_t *matrix);
