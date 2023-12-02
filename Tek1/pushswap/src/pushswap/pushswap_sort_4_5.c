/*
** EPITECH PROJECT, 2022
** pushswap_sort_4_5.c
** File description:
** pushswap_sort_4_5.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/operations.h"

static bool_t is_sorted(deque_t *list)
{
    for (u64_t i = 0; i + 1 < list->length; i++) {
        if (*(u32_t *)deque_get(list, i) > *(u32_t *)deque_get(list, i + 1))
            return false;
    }
    return true;
}

static u32_t get(deque_t *deque, u64_t index)
{
    return *(u32_t *)deque_get(deque, index);
}

static void insert_b_in_a(pushswap_t *ps)
{
    uint32_t i = 0;

    for (; get(&ps->l_a, 0) < get(&ps->l_b, 0); i++)
        pushswap_apply_ra(ps);
    pushswap_apply_pa(ps);
}

void pushswap_sort_4_5(pushswap_t *ps)
{
    while (ps->l_a.length != 3)
        pushswap_apply_pb(ps);
    pushswap_sort_3(ps);
    while (ps->l_b.length)
        insert_b_in_a(ps);
    while (!is_sorted(&ps->l_a))
        pushswap_apply_ra(ps);
}
