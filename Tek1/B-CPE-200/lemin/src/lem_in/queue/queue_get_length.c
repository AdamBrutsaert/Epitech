/*
** EPITECH PROJECT, 2023
** queue_get_length.c
** File description:
** queue_get_length.c
*/

#include "lem_in/queue_impl.h"

size_t queue_get_length(queue_t *queue)
{
    return queue->length;
}
