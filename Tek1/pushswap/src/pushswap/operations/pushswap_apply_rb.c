/*
** EPITECH PROJECT, 2022
** pushswap_apply_rb.c
** File description:
** pushswap_apply_rb.c
*/

#include "pushswap/operations.h"

void pushswap_apply_rb(pushswap_t *ps)
{
    i32_t value;
    u8_t op = RB;

    if (ps->l_b.length > 1) {
        deque_pop_front(&ps->l_b, &value);
        deque_push_back(&ps->l_b, &value);
        vector_push(&ps->operations, &op);
    }
}
