/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** sokoban.c
*/

#include "sokoban/sokoban.h"
#include "my/string.h"

status_t sokoban(int argc, char **argv, char **env)
{
    sokoban_map_t map;
    status_t status;

    if (argc != 2)
        return 84;
    if (!my_strcmp(argv[1], "-h"))
        return sokoban_help(argv[0]);
    if (!env[0])
        return 84;
    if (sokoban_map_create(&map, argv[1]))
        return 84;
    status = sokoban_run(&map);
    if (status != 84)
        sokoban_map_destroy(&map);
    return status;
}
