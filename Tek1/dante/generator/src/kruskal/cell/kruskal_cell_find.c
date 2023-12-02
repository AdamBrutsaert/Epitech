/*
** EPITECH PROJECT, 2023
** kruskal_cell_find.c.c
** File description:
** kruskal_cell_find.c.c
*/

#include "kruskal.h"

kruskal_cell_t *kruskal_cell_find(kruskal_cell_t *cell)
{
    kruskal_cell_t *parent;

    while (cell->parent != cell) {
        parent = cell->parent;
        cell->parent = cell->parent->parent;
        cell = parent;
    }
    return cell;
}
