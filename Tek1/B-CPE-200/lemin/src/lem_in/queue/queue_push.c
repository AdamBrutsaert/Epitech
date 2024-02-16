/*
** EPITECH PROJECT, 2023
** queue_push.c
** File description:
** queue_push.c
*/

#include "lem_in/queue_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(queue_t *queue)
{
    size_t capacity = queue->capacity * 2 + !queue->capacity;
    room_t **rooms = malloc(sizeof(room_t *) * capacity);

    if (rooms == NULL)
        return false;
    my_memcpy(rooms, queue->rooms, sizeof(room_t *) * queue->length);
    free(queue->rooms);
    queue->rooms = rooms;
    queue->capacity = capacity;
    return true;
}

bool queue_push(queue_t *queue, room_t *room)
{
    if (queue->length == queue->capacity && !grow(queue))
        return false;
    queue->rooms[queue->length] = room;
    queue->length++;
    return true;
}
