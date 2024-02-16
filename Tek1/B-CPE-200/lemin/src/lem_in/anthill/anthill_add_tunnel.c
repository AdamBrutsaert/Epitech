/*
** EPITECH PROJECT, 2023
** anthill_add_tunnel.c
** File description:
** anthill_add_tunnel.c
*/

#include "lem_in/anthill_impl.h"

bool anthill_add_tunnel(
    anthill_t *anthill,
    const char *name1,
    const char *name2
)
{
    room_node_t *room1 = anthill_get_room_node(anthill, name1);
    room_node_t *room2 = anthill_get_room_node(anthill, name2);
    size_t id1;
    size_t id2;

    if (room1 == NULL || room2 == NULL)
        return false;
    id1 = room_get_id(room1->room);
    id2 = room_get_id(room2->room);
    matrix_set(anthill->matrix, id1, id2, true);
    matrix_set(anthill->matrix, id2, id1, true);
    return true;
}
