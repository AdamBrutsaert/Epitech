/*
** EPITECH PROJECT, 2022
** deque_push_front.c
** File description:
** deque_push_front.c
*/

#include "my/deque.h"
#include "my/memory.h"

status_t deque_push_front(deque_t *deque, void const *value)
{
    my_memmove((i8_t *)deque->values + deque->front * deque->stride, value,
        deque->stride);
    if (deque->length + 1 == deque->capacity
        && deque_reserve(deque, deque->capacity * 2) == STATUS_ERROR)
        return STATUS_ERROR;
    deque->front = (!deque->front * deque->capacity + deque->front) - 1;
    deque->length++;
    return STATUS_SUCCESS;
}
