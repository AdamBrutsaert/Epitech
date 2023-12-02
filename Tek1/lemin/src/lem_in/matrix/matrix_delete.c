/*
** EPITECH PROJECT, 2023
** matrix_delete.c
** File description:
** matrix_delete.c
*/

#include "lem_in/matrix_impl.h"

#include <stdlib.h>

void matrix_delete(matrix_t *matrix)
{
    if (matrix == NULL)
        return;
    free(matrix->data);
    free(matrix);
}
