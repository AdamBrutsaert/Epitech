/*
** EPITECH PROJECT, 2023
** queue_pop.c
** File description:
** queue_pop.c
*/

#include "solver.h"

#include <string.h>

void queue_pop(queue_t *queue, position_t *position)
{
    if (!queue->length)
        return;
    queue->length--;
    memcpy(position, queue->positions, sizeof(position_t));
    memmove(queue->positions, &queue->positions[1],
        sizeof(position_t) * queue->length);
}
