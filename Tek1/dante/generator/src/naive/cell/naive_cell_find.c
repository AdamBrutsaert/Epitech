/*
** EPITECH PROJECT, 2023
** naive_cell_find.c.c
** File description:
** naive_cell_find.c.c
*/

#include "naive.h"

naive_cell_t *naive_cell_find(naive_cell_t *cell)
{
    naive_cell_t *parent;

    while (cell->parent != cell) {
        parent = cell->parent;
        cell->parent = cell->parent->parent;
        cell = parent;
    }
    return cell;
}
