/*
** EPITECH PROJECT, 2023
** room_set_name.c
** File description:
** room_set_name.c
*/

#include "lem_in/room_impl.h"

void room_set_name(room_t *room, char *name)
{
    room->name = name;
}
