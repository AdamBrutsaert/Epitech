/*
** EPITECH PROJECT, 2022
** deque_pop_back.c
** File description:
** deque_pop_back.c
*/

#include "my/deque.h"
#include "my/memory.h"

bool_t deque_pop_back(deque_t *deque, void *value)
{
    if (!deque->length)
        return false;
    deque->back = (!deque->back * deque->capacity + deque->back) - 1;
    deque->length--;
    if (value)
        my_memcpy(value, (i8_t *)deque->values + deque->back * deque->stride,
            deque->stride);
    return true;
}
