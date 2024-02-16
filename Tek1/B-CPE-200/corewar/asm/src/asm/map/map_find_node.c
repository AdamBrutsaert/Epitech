/*
** EPITECH PROJECT, 2023
** map_find_node.c
** File description:
** map_find_node.c
*/

#include "asm/map_impl.h"
#include "my/string.h"

map_node_t *map_find_node(map_t *map, const char *key)
{
    size_t hash = my_strhash(key);
    map_node_t *node = map->nodes[hash % MAP_SIZE];

    for (; node; node = node->next)
        if (!my_strcmp(node->key, key))
            return node;
    return NULL;
}
