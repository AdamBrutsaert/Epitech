/*
** EPITECH PROJECT, 2022
** deque_push_back.c
** File description:
** deque_push_back.c
*/

#include "my/deque.h"
#include "my/memory.h"

status_t deque_push_back(deque_t *deque, void const *value)
{
    my_memmove((i8_t *)deque->values + deque->back * deque->stride, value,
        deque->stride);
    if (deque->length + 1 == deque->capacity
        && deque_reserve(deque, deque->capacity * 2) == STATUS_ERROR)
        return STATUS_ERROR;
    deque->back = (deque->back + 1) % deque->capacity;
    deque->length++;
    return STATUS_SUCCESS;
}
