/*
** EPITECH PROJECT, 2022
** sokoban_map_destroy.c
** File description:
** sokoban_map_destroy.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/memory.h"

void sokoban_map_destroy(sokoban_map_t *map)
{
    vector_destroy(&map->objectives);
    vector_destroy(&map->boxes);
    my_free(map->rows[0]);
    my_free(map->rows);
}
