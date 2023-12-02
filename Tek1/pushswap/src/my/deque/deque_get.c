/*
** EPITECH PROJECT, 2022
** deque_get.c
** File description:
** deque_get.c
*/

#include "my/deque.h"

void const *deque_get(deque_t *deque, u64_t index)
{
    if (index >= deque->length)
        return nullptr;
    if (index >= deque->capacity - deque->front - 1)
        return (i8_t *)deque->values
            + (index - deque->capacity + deque->front + 1) * deque->stride;
    return (i8_t *)deque->values + (deque->front + index + 1) * deque->stride;
}
