/*
** EPITECH PROJECT, 2022
** pushswap_apply_sb.c
** File description:
** pushswap_apply_sb.c
*/

#include "pushswap/operations.h"

void pushswap_apply_sb(pushswap_t *ps)
{
    u32_t copy;
    u8_t op = SB;

    if (ps->l_b.length > 1) {
        copy = *(u32_t *)(deque_get(&ps->l_b, 0));
        deque_set(&ps->l_b, 0, deque_get(&ps->l_b, 1));
        deque_set(&ps->l_b, 1, &copy);
        vector_push(&ps->operations, &op);
    }
}
