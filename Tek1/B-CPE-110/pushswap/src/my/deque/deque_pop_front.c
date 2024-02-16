/*
** EPITECH PROJECT, 2022
** deque_pop_front.c
** File description:
** deque_pop_front.c
*/

#include "my/deque.h"
#include "my/memory.h"

bool_t deque_pop_front(deque_t *deque, void *value)
{
    if (!deque->length)
        return false;
    deque->front = (deque->front + 1) % deque->capacity;
    deque->length--;
    if (value)
        my_memcpy(value, (i8_t *)deque->values + deque->front * deque->stride,
            deque->stride);
    return true;
}
