/*
** EPITECH PROJECT, 2024
** ex05_2.c
** File description:
** ex05_2.c
*/

#include "stack.h"

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
