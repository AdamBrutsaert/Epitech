/*
** EPITECH PROJECT, 2023
** anthill_set_start.c
** File description:
** anthill_set_start.c
*/

#include "lem_in/anthill_impl.h"

bool anthill_set_start(anthill_t *anthill, const char *name)
{
    room_node_t *node;

    if (anthill->start != NULL)
        return false;
    node = anthill_get_room_node(anthill, name);
    if (node == NULL)
        return false;
    anthill->start = node->room;
    return true;
}
