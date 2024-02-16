/*
** EPITECH PROJECT, 2023
** kruskal_from_args.c
** File description:
** kruskal_from_args.c
*/

#include "kruskal.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

static bool kruskal_parse_args(int argc, char **argv, uint32_t *width,
    uint32_t *height)
{
    char *end;

    if (argc != 4 || strcmp(argv[3], "perfect"))
        return false;
    *width = strtoul(argv[1], &end, 10);
    if (*end != '\0')
        return false;
    *height = strtoul(argv[2], &end, 10);
    if (*end != '\0')
        return false;
    return true;
}

int kruskal_from_args(int argc, char **argv)
{
    uint32_t width;
    uint32_t height;
    kruskal_maze_t *maze;

    if (!kruskal_parse_args(argc, argv, &width, &height))
        return 84;
    if (width < 1 || height < 1)
        return 84;
    maze = kruskal_maze_create(width, height);
    if (maze == NULL)
        return 84;
    kruskal_maze_generate(maze);
    kruskal_maze_print(maze);
    kruskal_maze_destroy(maze);
    return 0;
}
