/*
** EPITECH PROJECT, 2023
** anthill_get_room_from_id.c
** File description:
** anthill_get_room_from_id.c
*/

#include "lem_in/anthill_impl.h"

static room_t *return_if_id_matches(
    anthill_t *anthill,
    size_t i,
    size_t id
)
{
    room_node_t *node;

    node = anthill->rooms[i];
    while (node != NULL) {
        if (room_get_id(node->room) == id)
            return node->room;
        node = node->next;
    }
    return NULL;
}

room_t *anthill_get_room_from_id(anthill_t *anthill, size_t id)
{
    room_t *room;

    for (size_t i = 0; i < ROOMS_HASHMAP_SIZE; i++) {
        room = return_if_id_matches(anthill, i, id);
        if (room != NULL)
            return room;
    }
    return NULL;
}
