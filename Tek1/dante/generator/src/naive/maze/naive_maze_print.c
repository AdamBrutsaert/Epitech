/*
** EPITECH PROJECT, 2023
** naive_maze_print.c
** File description:
** naive_maze_print.c
*/

#include "naive.h"

#include <stdio.h>

void naive_maze_print(naive_maze_t *maze)
{
    for (uint32_t y = 0; y < maze->height; y++) {
        for (uint32_t x = 0; x < maze->width; x++) {
            printf("%c", maze->cells[y * maze->width + x].type == NAIVE_EMPTY
                    ? '*' : 'X');
        }
        if (y + 1 != maze->height)
            printf("\n");
    }
}
