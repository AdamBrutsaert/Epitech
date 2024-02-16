/*
** EPITECH PROJECT, 2023
** queue_delete.c
** File description:
** queue_delete.c
*/

#include "lem_in/queue_impl.h"

#include <stdlib.h>

void queue_delete(queue_t *queue)
{
    if (queue == NULL)
        return;
    free(queue->rooms);
    free(queue);
}
