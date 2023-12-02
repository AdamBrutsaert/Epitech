/*
** EPITECH PROJECT, 2023
** queue_new.c
** File description:
** queue_new.c
*/

#include "lem_in/queue_impl.h"
#include "my/memory.h"

queue_t *queue_new(void)
{
    return my_calloc(sizeof(queue_t));
}
