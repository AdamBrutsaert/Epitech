/*
** EPITECH PROJECT, 2022
** deque_set.c
** File description:
** deque_set.c
*/

#include "my/deque.h"
#include "my/memory.h"

status_t deque_set(deque_t *deque, u64_t index, void const *value)
{
    if (index >= deque->length)
        return STATUS_ERROR;
    if (index >= deque->capacity - deque->front - 1) {
        my_memcpy((i8_t *)deque->values
            + (index - deque->capacity + deque->front + 1) * deque->stride,
            value, deque->stride);
    } else {
        my_memcpy((i8_t *)deque->values
            + (deque->front + index + 1) * deque->stride,
            value, deque->stride);
    }
    return STATUS_SUCCESS;
}
