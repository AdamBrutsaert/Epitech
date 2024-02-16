/*
** EPITECH PROJECT, 2023
** room_new.c
** File description:
** room_new.c
*/

#include "lem_in/room_impl.h"
#include "my/memory.h"

room_t *room_new(void)
{
    static size_t id = 0;
    room_t *room = my_calloc(sizeof(room_t));

    if (room == NULL)
        return NULL;
    room->id = id;
    id++;
    return room;
}
