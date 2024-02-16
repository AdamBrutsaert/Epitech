/*
** EPITECH PROJECT, 2022
** pushswap_apply_pa.c
** File description:
** pushswap_apply_pa.c
*/

#include "pushswap/operations.h"

void pushswap_apply_pa(pushswap_t *ps)
{
    i32_t value;
    u8_t op = PA;

    if (ps->l_b.length) {
        deque_pop_front(&ps->l_b, &value);
        deque_push_front(&ps->l_a, &value);
        vector_push(&ps->operations, &op);
    }
}
