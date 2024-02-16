/*
** EPITECH PROJECT, 2023
** map_new.c
** File description:
** map_new.c
*/

#include "asm/map_impl.h"
#include "my/memory.h"

map_t *map_new(void)
{
    map_t *map = my_malloc(sizeof(map_t));

    map->nodes = my_calloc(sizeof(map_node_t *) * MAP_SIZE);
    map->arena = arena_new();
    return map;
}
