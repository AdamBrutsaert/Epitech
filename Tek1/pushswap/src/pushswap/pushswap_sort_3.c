/*
** EPITECH PROJECT, 2022
** pushswap_sort_3.c
** File description:
** pushswap_sort_3.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/operations.h"

static u32_t get(pushswap_t *ps, u64_t index)
{
    return *(u32_t *)deque_get(&ps->l_a, index);
}

void pushswap_sort_3(pushswap_t *ps)
{
    if (get(ps, 0) > get(ps, 1) && get(ps, 1) < get(ps, 2)
        && get(ps, 2) > get(ps, 0))
        pushswap_apply_sa(ps);
    if ((get(ps, 0) > get(ps, 1) && get(ps, 1) > get(ps, 2)
        && get(ps, 2) < get(ps, 0))) {
        pushswap_apply_sa(ps);
        pushswap_apply_rra(ps);
    }
    if ((get(ps, 0) > get(ps, 1) && get(ps, 1) < get(ps, 2)
        && get(ps, 2) < get(ps, 0)))
        pushswap_apply_ra(ps);
    if ((get(ps, 0) < get(ps, 1) && get(ps, 1) > get(ps, 2)
        && get(ps, 2) > get(ps, 0))) {
        pushswap_apply_sa(ps);
        pushswap_apply_ra(ps);
    }
    if ((get(ps, 0) < get(ps, 1) && get(ps, 1) > get(ps, 2)
        && get(ps, 2) < get(ps, 0)))
        pushswap_apply_rra(ps);
}
