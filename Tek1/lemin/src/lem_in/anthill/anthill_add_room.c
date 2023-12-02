/*
** EPITECH PROJECT, 2023
** anthill_add_room.c
** File description:
** anthill_add_room.c
*/

#include "lem_in/anthill_impl.h"
#include "my/string.h"

#include <stdlib.h>

bool anthill_add_room(anthill_t *anthill, room_t *room)
{
    room_node_t *node = anthill_get_room_node(anthill, room_get_name(room));
    room_t *same = anthill_get_room_from_coordinates(anthill, room_get_x(room),
        room_get_y(room));
    size_t hash;

    if (node != NULL || same != NULL)
        return false;
    if (matrix_get_size(anthill->matrix) <= room_get_id(room)) {
        if (!matrix_resize(anthill->matrix, room_get_id(room) + 1))
            return false;
    }
    node = malloc(sizeof(room_node_t));
    if (node == NULL)
        return false;
    node->room = room;
    hash = my_strhash(room_get_name(room)) % ROOMS_HASHMAP_SIZE;
    node->next = anthill->rooms[hash];
    anthill->rooms[hash] = node;
    anthill->length++;
    return true;
}
