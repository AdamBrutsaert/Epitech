/*
** EPITECH PROJECT, 2023
** anthill_delete.c
** File description:
** anthill_delete.c
*/

#include "lem_in/anthill_impl.h"

#include <stdlib.h>

static void anthill_delete_node(room_node_t *node)
{
    if (node == NULL)
        return;
    anthill_delete_node(node->next);
    room_delete(node->room);
    free(node);
}

void anthill_delete(anthill_t *anthill)
{
    if (anthill == NULL)
        return;
    for (size_t i = 0; i < ROOMS_HASHMAP_SIZE; i++)
        anthill_delete_node(anthill->rooms[i]);
    matrix_delete(anthill->matrix);
    free(anthill->rooms);
    free(anthill);
}
