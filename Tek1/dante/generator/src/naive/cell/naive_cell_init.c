/*
** EPITECH PROJECT, 2023
** cell_init.c
** File description:
** cell_init.c
*/

#include "naive.h"

void naive_cell_make(naive_cell_t *cell, naive_cell_type_t type)
{
    cell->parent = cell;
    cell->rank = 0;
    cell->type = type;
}
