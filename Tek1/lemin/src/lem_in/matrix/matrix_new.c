/*
** EPITECH PROJECT, 2023
** matrix_new.c
** File description:
** matrix_new.c
*/

#include "lem_in/matrix_impl.h"
#include "my/memory.h"

#include <stdlib.h>

matrix_t *matrix_new(size_t size)
{
    matrix_t *matrix = my_calloc(sizeof(matrix_t));

    if (matrix == NULL)
        return NULL;
    matrix->size = size;
    matrix->data = my_calloc(sizeof(int8_t) * size * size);
    if (matrix->data == NULL && size != 0) {
        matrix_delete(matrix);
        return NULL;
    }
    return matrix;
}
