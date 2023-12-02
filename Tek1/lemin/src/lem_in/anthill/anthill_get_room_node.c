/*
** EPITECH PROJECT, 2023
** anthill_get_room_node.c
** File description:
** anthill_get_room_node.c
*/

#include "lem_in/anthill_impl.h"
#include "my/string.h"

room_node_t *anthill_get_room_node(anthill_t *anthill, char const *name)
{
    size_t hash = my_strhash(name) % ROOMS_HASHMAP_SIZE;
    room_node_t *node = anthill->rooms[hash];

    for (; node != NULL; node = node->next) {
        if (!my_strcmp(room_get_name(node->room), name))
            return node;
    }
    return NULL;
}
