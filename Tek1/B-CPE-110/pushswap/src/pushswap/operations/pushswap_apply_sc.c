/*
** EPITECH PROJECT, 2022
** pushswap_apply_sc.c
** File description:
** pushswap_apply_sc.c
*/

#include "pushswap/operations.h"

void pushswap_apply_sc(pushswap_t *ps)
{
    u32_t copy;
    u8_t op = SC;

    if (ps->l_a.length > 1) {
        copy = *(u32_t *)(deque_get(&ps->l_a, 0));
        deque_set(&ps->l_a, 0, deque_get(&ps->l_a, 1));
        deque_set(&ps->l_a, 1, &copy);
    }
    if (ps->l_b.length > 1) {
        copy = *(u32_t *)(deque_get(&ps->l_b, 0));
        deque_set(&ps->l_b, 0, deque_get(&ps->l_b, 1));
        deque_set(&ps->l_b, 1, &copy);
    }
    if (ps->l_a.length > 1 || ps->l_b.length > 1)
        vector_push(&ps->operations, &op);
}
