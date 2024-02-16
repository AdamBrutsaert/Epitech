/*
** EPITECH PROJECT, 2022
** pushswap_apply_ra.c
** File description:
** pushswap_apply_ra.c
*/

#include "pushswap/operations.h"

void pushswap_apply_ra(pushswap_t *ps)
{
    i32_t value;
    u8_t op = RA;

    if (ps->l_a.length > 1) {
        deque_pop_front(&ps->l_a, &value);
        deque_push_back(&ps->l_a, &value);
        vector_push(&ps->operations, &op);
    }
}
