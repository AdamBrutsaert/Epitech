/*
** EPITECH PROJECT, 2024
** ex06_2.c
** File description:
** ex06_2.c
*/

#include "queue.h"

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_front(queue);
}
