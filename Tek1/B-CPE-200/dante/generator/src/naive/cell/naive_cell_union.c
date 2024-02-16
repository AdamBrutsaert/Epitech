/*
** EPITECH PROJECT, 2023
** naive_cell_union.c
** File description:
** naive_cell_union.c
*/

#include "naive.h"

static void naive_cell_swap(naive_cell_t **c1, naive_cell_t **c2)
{
    naive_cell_t *copy = *c1;

    *c1 = *c2;
    *c2 = copy;
}

void naive_cell_union(naive_cell_t *c1, naive_cell_t *c2)
{
    c1 = naive_cell_find(c1);
    c2 = naive_cell_find(c2);
    if (c1 == c2)
        return;
    if (c1->rank < c2->rank)
        naive_cell_swap(&c1, &c2);
    c2->parent = c1;
    c1->rank += c1->rank == c2->rank;
}
