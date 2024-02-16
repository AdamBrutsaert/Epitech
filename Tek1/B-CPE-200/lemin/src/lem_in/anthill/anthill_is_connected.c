/*
** EPITECH PROJECT, 2023
** anthill_is_connected.c
** File description:
** anthill_is_connected.c
*/

#include "lem_in/anthill_impl.h"

bool anthill_is_connected(anthill_t *anthill, size_t id1, size_t id2)
{
    size_t size = matrix_get_size(anthill->matrix);

    if (id1 >= size || id2 >= size)
        return false;
    return matrix_get(anthill->matrix, id1, id2);
}
