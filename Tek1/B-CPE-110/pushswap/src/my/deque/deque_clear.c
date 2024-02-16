/*
** EPITECH PROJECT, 2022
** deque_clear.c
** File description:
** deque_clear.c
*/

#include "my/deque.h"
#include "my/memory.h"

void deque_clear(deque_t *deque)
{
    deque->length = 0;
    deque->back = 0;
    deque->front = deque->capacity - 1;
}
