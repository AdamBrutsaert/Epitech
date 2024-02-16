/*
** EPITECH PROJECT, 2023
** kruskal_cell_union.c
** File description:
** kruskal_cell_union.c
*/

#include "kruskal.h"

static void kruskal_cell_swap(kruskal_cell_t **c1, kruskal_cell_t **c2)
{
    kruskal_cell_t *copy = *c1;

    *c1 = *c2;
    *c2 = copy;
}

void kruskal_cell_union(kruskal_cell_t *c1, kruskal_cell_t *c2)
{
    c1 = kruskal_cell_find(c1);
    c2 = kruskal_cell_find(c2);
    if (c1 == c2)
        return;
    if (c1->rank < c2->rank)
        kruskal_cell_swap(&c1, &c2);
    c2->parent = c1;
    c1->rank += c1->rank == c2->rank;
}
