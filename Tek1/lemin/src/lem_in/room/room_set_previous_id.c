/*
** EPITECH PROJECT, 2023
** room_set_previous_id.c
** File description:
** room_set_previous_id.c
*/

#include "lem_in/room_impl.h"

void room_set_previous_id(room_t *room, size_t id)
{
    room->previous_id = id;
}
