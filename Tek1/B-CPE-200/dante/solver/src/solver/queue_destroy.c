/*
** EPITECH PROJECT, 2023
** queue_destroy.c
** File description:
** queue_destroy.c
*/

#include "solver.h"

#include <stdlib.h>

void queue_destroy(queue_t *queue)
{
    free(queue->positions);
    free(queue);
}
