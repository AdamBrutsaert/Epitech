/*
** EPITECH PROJECT, 2023
** queue_create.c
** File description:
** queue_create.c
*/

#include "solver.h"

#include <stdlib.h>

queue_t *queue_create(void)
{
    queue_t *queue = calloc(1, sizeof(queue_t));

    if (!queue)
        return NULL;
    queue->positions = NULL;
    queue->length = 0;
    queue->capacity = 0;
    return queue;
}
