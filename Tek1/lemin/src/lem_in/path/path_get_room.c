/*
** EPITECH PROJECT, 2023
** path_get_room.c
** File description:
** path_get_room.c
*/

#include "lem_in/path_impl.h"

room_t *path_get_room(path_t *path, size_t index)
{
    return path->rooms[index];
}
