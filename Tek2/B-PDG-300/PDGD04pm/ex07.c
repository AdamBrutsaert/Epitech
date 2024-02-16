/*
** EPITECH PROJECT, 2024
** ex07.c
** File description:
** ex07.c
*/

#include "map.h"

#include <stdlib.h>

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

bool map_add_elem(
    map_t **map_ptr,
    void *key,
    void *value,
    key_comparator_t key_cmp
)
{
    list_t *node = *map_ptr;
    pair_t *pair = NULL;

    for (; node; node = node->next) {
        if (key_cmp(((pair_t *)(node->value))->key, key) == 0) {
            ((pair_t *)(node->value))->value = value;
            return true;
        }
    }
    pair = calloc(1, sizeof(pair_t));
    if (pair == NULL)
        return false;
    pair->key = key;
    pair->value = value;
    return list_add_elem_at_back(map_ptr, pair);
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    for (; map; map = map->next) {
        if (key_cmp(((pair_t *)(map->value))->key, key) == 0)
            return ((pair_t *)(map->value))->value;
    }
    return NULL;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    size_t index = 0;

    for (list_t *node = *map_ptr; node != NULL; node = node->next) {
        if (key_cmp(((pair_t *)((node)->value))->key, key) == 0) {
            free(node->value);
            list_del_elem_at_position(map_ptr, index);
            return true;
        }
        index++;
    }
    return false;
}
