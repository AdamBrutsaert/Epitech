/*
** EPITECH PROJECT, 2023
** room_set_visited.c
** File description:
** room_set_visited.c
*/

#include "lem_in/room_impl.h"

void room_set_visited(room_t *room, bool status)
{
    room->visited = status;
}
