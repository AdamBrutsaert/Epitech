/*
** EPITECH PROJECT, 2022
** pushswap_apply_pb.c
** File description:
** pushswap_apply_pb.c
*/

#include "pushswap/operations.h"

void pushswap_apply_pb(pushswap_t *ps)
{
    i32_t value;
    u8_t op = PB;

    if (ps->l_a.length) {
        deque_pop_front(&ps->l_a, &value);
        deque_push_front(&ps->l_b, &value);
        vector_push(&ps->operations, &op);
    }
}
