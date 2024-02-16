/*
** EPITECH PROJECT, 2023
** matrix.h
** File description:
** matrix.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct matrix matrix_t;

/**
 * @brief Allocate a new matrix
 *
 * @param size the size of the matrix
 * @return matrix_t* the matrix
 */
matrix_t *matrix_new(size_t size);

/**
 * @brief Free a matrix
 *
 * @param matrix the matrix
 */
void matrix_delete(matrix_t *matrix);

/**
 * @brief Get the size of a matrix
 *
 * @param matrix the matrix
 * @return size_t the size
 */
size_t matrix_get_size(matrix_t *matrix);

/**
 * @brief Resize a matrix
 *
 * @param matrix the matrix
 * @param size the new size
 * @return true if the matrix was resized
 * @return false if the matrix was not resized
 */
bool matrix_resize(matrix_t *matrix, size_t size);

/**
 * @brief Set a value in the matrix
 *
 * @param matrix the matrix
 * @param row the row
 * @param colum the column
 * @param value the value
 */
void matrix_set(matrix_t *matrix, size_t row, size_t column, int8_t value);

/**
 * @brief Get a value in the matrix
 *
 * @param matrix the matrix
 * @param row the row
 * @param column the column
 * @return int8_t the value
 */
int8_t matrix_get(matrix_t *matrix, size_t row, size_t column);
