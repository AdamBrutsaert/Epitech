/*
** EPITECH PROJECT, 2023
** gol_print.c
** File description:
** gol_print.c
*/

#include "gameoflife.h"
#include "my/stdio.h"

void gol_print(gol_t *gol)
{
    my_puts(gol->current);
}
