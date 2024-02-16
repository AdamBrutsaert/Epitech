/*
** EPITECH PROJECT, 2023
** cell_init.c
** File description:
** cell_init.c
*/

#include "kruskal.h"

void kruskal_cell_make(kruskal_cell_t *cell, kruskal_cell_type_t type)
{
    cell->parent = cell;
    cell->rank = 0;
    cell->type = type;
}
