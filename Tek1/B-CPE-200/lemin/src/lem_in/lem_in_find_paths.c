/*
** EPITECH PROJECT, 2023
** lem_in_find_paths.c
** File description:
** lem_in_find_paths.c
*/

#include "lem_in_impl.h"


static bool add_path2(lem_in_t *lem_in, path_t *path)
{
    path_reverse(path);
    if (lem_in_path_intersect(lem_in, path)) {
        path_delete(path);
        return true;
    }
    if (!lem_in_add_path(lem_in, path)) {
        path_delete(path);
        return false;
    }
    return true;
}

static bool add_path(lem_in_t *lem_in)
{
    path_t *path = path_new();
    room_t *room = anthill_get_end(lem_in->anthill);
    size_t id = room_get_id(room);

    if (path == NULL)
        return false;
    while (id != room_get_id(anthill_get_start(lem_in->anthill))) {
        if (!path_add_room(path, room)) {
            path_delete(path);
            return false;
        }
        id = room_get_previous_id(room);
        room = anthill_get_room_from_id(lem_in->anthill, id);
    }
    return add_path2(lem_in, path);
}

static bool process_one2(lem_in_t *lem_in, size_t current_id)
{
    room_t *room;
    room_t *end_room = anthill_get_end(lem_in->anthill);
    size_t end_id = room_get_id(end_room);

    for (size_t i = 0; i < anthill_get_length(lem_in->anthill); i++) {
        room = anthill_get_room_from_id(lem_in->anthill, i);
        if (i == end_id || room_is_visited(room)
            || !anthill_is_connected(lem_in->anthill, current_id, i))
            continue;
        if (!queue_push(lem_in->queue, room))
            return false;
        room_set_previous_id(room, current_id);
        room_set_visited(room, true);
    }
    return true;
}

static bool process_one(lem_in_t *lem_in)
{
    room_t *current = queue_pop(lem_in->queue);
    room_t *end_room = anthill_get_end(lem_in->anthill);
    size_t current_id = room_get_id(current);
    size_t start_id = room_get_id(anthill_get_start(lem_in->anthill));
    size_t end_id = room_get_id(end_room);

    if (anthill_is_connected(lem_in->anthill, current_id, end_id)) {
        room_set_previous_id(end_room, current_id);
        add_path(lem_in);
        if (current_id != start_id)
            return true;
    }
    return process_one2(lem_in, current_id);
}

bool lem_in_find_paths(lem_in_t *lem_in)
{
    if (!queue_push(lem_in->queue, anthill_get_start(lem_in->anthill)))
        return false;
    room_set_visited(anthill_get_start(lem_in->anthill), true);
    while (queue_get_length(lem_in->queue) != 0) {
        if (!process_one(lem_in))
            return false;
    }
    return lem_in->length != 0;
}
