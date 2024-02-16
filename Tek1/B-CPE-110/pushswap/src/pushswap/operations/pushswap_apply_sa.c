/*
** EPITECH PROJECT, 2022
** pushswap_apply_sa.c
** File description:
** pushswap_apply_sa.c
*/

#include "pushswap/operations.h"

void pushswap_apply_sa(pushswap_t *ps)
{
    u32_t copy;
    u8_t op = SA;

    if (ps->l_a.length > 1) {
        copy = *(u32_t *)(deque_get(&ps->l_a, 0));
        deque_set(&ps->l_a, 0, deque_get(&ps->l_a, 1));
        deque_set(&ps->l_a, 1, &copy);
        vector_push(&ps->operations, &op);
    }
}
