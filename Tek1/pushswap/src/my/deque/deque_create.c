/*
** EPITECH PROJECT, 2022
** deque_create.c
** File description:
** deque_create.c
*/

#include "my/deque.h"
#include "my/memory.h"

status_t deque_create(deque_t *deque, u64_t stride)
{
    deque->values = my_malloc(stride);
    deque->capacity = 1;
    deque->length = 0;
    deque->stride = stride;
    deque->front = 0;
    deque->back = 0;
    return deque->values ? STATUS_SUCCESS : STATUS_ERROR;
}
