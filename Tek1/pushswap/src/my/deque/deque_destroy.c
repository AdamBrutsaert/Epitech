/*
** EPITECH PROJECT, 2022
** deque_destroy.c
** File description:
** deque_destroy.c
*/

#include "my/deque.h"
#include "my/memory.h"

void deque_destroy(deque_t *deque)
{
    my_free(deque->values);
}
