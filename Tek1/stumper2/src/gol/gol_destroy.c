/*
** EPITECH PROJECT, 2023
** gol_destroy.c
** File description:
** gol_destroy.c
*/

#include "gameoflife.h"
#include "my/memory.h"

void gol_destroy(gol_t *gol)
{
    if (gol == NULL)
        return;
    my_free(gol->current);
    my_free(gol->next);
    my_free(gol);
}
