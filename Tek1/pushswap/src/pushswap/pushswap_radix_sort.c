/*
** EPITECH PROJECT, 2022
** pushswap_radix_sort.c
** File description:
** pushswap_radix_sort.c
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

static u8_t get_iteration_count(pushswap_t *ps)
{
    u64_t length = ps->l_a.length;
    u8_t iterations = 0;

    for (; length; length /= 2)
        iterations++;
    return iterations;
}

static void radix_sort(pushswap_t *ps, u8_t iteration)
{
    u64_t length = ps->l_a.length;

    for (u64_t i = 0; i < length; i++) {
        if ((*(u32_t *)deque_get(&ps->l_a, 0) & (1 << iteration)) == 0) {
            pushswap_apply_pb(ps);
        } else {
            pushswap_apply_ra(ps);
        }
    }
    while (ps->l_b.length)
        pushswap_apply_pa(ps);
}

void pushswap_radix_sort(pushswap_t *ps)
{
    u8_t iteration = get_iteration_count(ps);

    for (uint32_t i = 0; i < iteration && !is_sorted(&ps->l_a); i++)
        radix_sort(ps, i);
}
