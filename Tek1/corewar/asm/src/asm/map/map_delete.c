/*
** EPITECH PROJECT, 2023
** map_delete.c
** File description:
** map_delete.c
*/

#include "asm/map_impl.h"
#include "my/memory.h"

void map_delete(map_t *map)
{
    arena_delete(map->arena);
    my_free(map->nodes);
    my_free(map);
}
