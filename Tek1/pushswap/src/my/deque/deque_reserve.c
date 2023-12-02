/*
** EPITECH PROJECT, 2022
** deque_reserve.c
** File description:
** deque_reserve.c
*/

#include "my/deque.h"
#include "my/memory.h"

status_t deque_reserve(deque_t *deque, u64_t capacity)
{
    void *values;
    u64_t count;

    if (capacity <= deque->capacity)
        return STATUS_ERROR;
    values = my_realloc(deque->values, capacity * deque->stride);
    if (!values)
        return STATUS_ERROR;
    count = deque->capacity - deque->front;
    my_memcpy((i8_t *)values + (capacity - count) * deque->stride,
        (i8_t *)values + (deque->capacity - count) * deque->stride,
        count * deque->stride);
    deque->front = capacity - count;
    deque->capacity = capacity;
    deque->values = values;
    return STATUS_SUCCESS;
}
