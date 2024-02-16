/*
** EPITECH PROJECT, 2023
** map_get.c
** File description:
** map_get.c
*/

#include "asm/map_impl.h"

size_t *map_get(map_t *map, const char *key)
{
    map_node_t *node = map_find_node(map, key);

    return node ? &node->value : NULL;
}
