/*
** EPITECH PROJECT, 2023
** room_delete.c
** File description:
** room_delete.c
*/

#include "lem_in/room_impl.h"

#include <stdlib.h>

void room_delete(room_t *room)
{
    if (room == NULL)
        return;
    free(room->name);
    free(room);
}
