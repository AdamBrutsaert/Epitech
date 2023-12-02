/*
** EPITECH PROJECT, 2023
** path_reverse.c
** File description:
** path_reverse.c
*/

#include "lem_in/path_impl.h"

static void swap(room_t **room1, room_t **room2)
{
    room_t *copy = *room1;

    *room1 = *room2;
    *room2 = copy;
}

void path_reverse(path_t *path)
{
    for (size_t i = 0; i < path->length / 2; i++)
        swap(&path->rooms[i], &path->rooms[path->length - i - 1]);
}
