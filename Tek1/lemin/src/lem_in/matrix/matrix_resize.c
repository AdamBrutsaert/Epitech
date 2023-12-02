/*
** EPITECH PROJECT, 2023
** matrix_resize.c
** File description:
** matrix_resize.c
*/

#include "lem_in/matrix_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static size_t min(size_t a, size_t b)
{
    return a < b ? a : b;
}

bool matrix_resize(matrix_t *matrix, size_t size)
{
    int8_t *data;
    size_t min_size = min(size, matrix->size);

    if (matrix->size == size)
        return true;
    data = my_calloc(sizeof(int8_t) * size * size);
    if (data == NULL && size)
        return false;
    for (size_t i = 0; i < min_size; i++) {
        for (size_t j = 0; j < min_size; j++)
            data[i * size + j] = matrix->data[i * matrix->size + j];
    }
    free(matrix->data);
    matrix->data = data;
    matrix->size = size;
    return true;
}
