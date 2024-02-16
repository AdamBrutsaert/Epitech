/*
** EPITECH PROJECT, 2023
** path_add_room.c
** File description:
** path_add_room.c
*/

#include "lem_in/path_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(path_t *path)
{
    size_t capacity = path->capacity * 2 + !path->capacity;
    room_t **rooms = malloc(sizeof(room_t *) * capacity);

    if (rooms == NULL)
        return false;
    my_memcpy(rooms, path->rooms, sizeof(room_t *) * path->length);
    free(path->rooms);
    path->rooms = rooms;
    path->capacity = capacity;
    return true;
}

bool path_add_room(path_t *path, room_t *room)
{
    if (path->length == path->capacity && !grow(path))
        return false;
    path->rooms[path->length] = room;
    path->length++;
    return true;
}
