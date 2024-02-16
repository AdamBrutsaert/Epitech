/*
** EPITECH PROJECT, 2023
** queue_push.c
** File description:
** queue_push.c
*/

#include "solver.h"

#include <stdlib.h>

bool queue_push(queue_t *queue, uint32_t x, uint32_t y)
{
    uint64_t capacity;
    position_t *buffer;

    if (queue->length == queue->capacity) {
        capacity = queue->capacity * 2 + !queue->capacity;
        buffer = realloc(queue->positions, capacity * sizeof(position_t));
        if (!buffer)
            return false;
        queue->positions = buffer;
        queue->capacity = capacity;
    }
    queue->positions[queue->length].x = x;
    queue->positions[queue->length].y = y;
    queue->length++;
    return true;
}
