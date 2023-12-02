/*
** EPITECH PROJECT, 2023
** map_set.c
** File description:
** map_set.c
*/

#include "asm/map_impl.h"
#include "my/memory.h"
#include "my/string.h"

void map_set(map_t *map, const char *key, size_t value)
{
    size_t hash = my_strhash(key);
    map_node_t *node = map_find_node(map, key);

    if (node != NULL)
        return;
    node = arena_malloc(map->arena, sizeof(map_node_t));
    node->key = arena_calloc(map->arena, my_strlen(key) + 1);
    node->value = value;
    node->next = map->nodes[hash % MAP_SIZE];
    my_memcpy(node->key, key, my_strlen(key));
    map->nodes[hash % MAP_SIZE] = node;
}
