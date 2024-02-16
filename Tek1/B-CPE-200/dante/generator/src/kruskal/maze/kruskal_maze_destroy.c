/*
** EPITECH PROJECT, 2023
** kruskal_maze_destroy.c
** File description:
** kruskal_maze_destroy.c
*/

#include "kruskal.h"

#include <stdlib.h>

void kruskal_maze_destroy(kruskal_maze_t *maze)
{
    free(maze->cells);
    free(maze->walls);
    free(maze);
}
