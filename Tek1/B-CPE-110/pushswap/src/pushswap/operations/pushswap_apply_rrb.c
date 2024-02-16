/*
** EPITECH PROJECT, 2022
** pushswap_apply_rrb.c
** File description:
** pushswap_apply_rrb.c
*/

#include "pushswap/operations.h"

void pushswap_apply_rrb(pushswap_t *ps)
{
    i32_t value;
    u8_t op = RRB;

    if (ps->l_b.length > 1) {
        deque_pop_back(&ps->l_b, &value);
        deque_push_front(&ps->l_b, &value);
        vector_push(&ps->operations, &op);
    }
}
