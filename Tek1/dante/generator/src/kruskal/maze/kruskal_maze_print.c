/*
** EPITECH PROJECT, 2023
** kruskal_maze_print.c
** File description:
** kruskal_maze_print.c
*/

#include "kruskal.h"

#include <stdio.h>

void kruskal_maze_print(kruskal_maze_t *maze)
{
    for (uint32_t y = 0; y < maze->height; y++) {
        for (uint32_t x = 0; x < maze->width; x++) {
            printf("%c", maze->cells[y * maze->width + x].type == KRUSKAL_EMPTY
                    ? '*' : 'X');
        }
        if (y + 1 != maze->height)
            printf("\n");
    }
}
