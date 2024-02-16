/*
** EPITECH PROJECT, 2023
** anthill_get_room_from_coordinates.c
** File description:
** anthill_get_room_from_coordinates.c
*/

#include "lem_in/anthill_impl.h"

static room_t *return_if_coordinates_matches(
    anthill_t *anthill,
    size_t i,
    int32_t x,
    int32_t y
)
{
    room_node_t *node;

    node = anthill->rooms[i];
    while (node != NULL) {
        if (room_get_x(node->room) == x && room_get_y(node->room) == y)
            return node->room;
        node = node->next;
    }
    return NULL;
}

room_t *anthill_get_room_from_coordinates(
    anthill_t *anthill,
    int32_t x,
    int32_t y
)
{
    room_t *room;

    for (size_t i = 0; i < ROOMS_HASHMAP_SIZE; i++) {
        room = return_if_coordinates_matches(anthill, i, x, y);
        if (room != NULL)
            return room;
    }
    return NULL;
}
