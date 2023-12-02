/*
** EPITECH PROJECT, 2022
** pushswap_apply_rr.c
** File description:
** pushswap_apply_rr.c
*/

#include "pushswap/operations.h"

void pushswap_apply_rr(pushswap_t *ps)
{
    i32_t value;
    u8_t op = RR;

    if (ps->l_a.length > 1) {
        deque_pop_front(&ps->l_a, &value);
        deque_push_back(&ps->l_a, &value);
    }
    if (ps->l_b.length > 1) {
        deque_pop_front(&ps->l_b, &value);
        deque_push_back(&ps->l_b, &value);
    }
    if (ps->l_a.length > 1 || ps->l_b.length > 1)
        vector_push(&ps->operations, &op);
}
