/*
** EPITECH PROJECT, 2023
** anthill_set_end.c
** File description:
** anthill_set_end.c
*/

#include "lem_in/anthill_impl.h"

bool anthill_set_end(anthill_t *anthill, const char *name)
{
    room_node_t *node;

    if (anthill->end != NULL)
        return false;
    node = anthill_get_room_node(anthill, name);
    if (node == NULL)
        return false;
    anthill->end = node->room;
    return true;
}
