/*
** EPITECH PROJECT, 2023
** queue_pop.c
** File description:
** queue_pop.c
*/

#include "lem_in/queue_impl.h"
#include "my/memory.h"

room_t *queue_pop(queue_t *queue)
{
    room_t *room;

    if (queue->length == 0)
        return NULL;
    room = queue->rooms[0];
    queue->length--;
    my_memmove(
        queue->rooms,
        queue->rooms + 1,
        sizeof(room_t *) * queue->length
    );
    return room;
}
