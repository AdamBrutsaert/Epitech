/*
** EPITECH PROJECT, 2022
** pushswap_sort_2.c
** File description:
** pushswap_sort_2.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/operations.h"

void pushswap_sort_2(pushswap_t *ps)
{
    if (*(u32_t *)deque_get(&ps->l_a, 0) > *(u32_t *)deque_get(&ps->l_a, 1))
        pushswap_apply_sa(ps);
}
