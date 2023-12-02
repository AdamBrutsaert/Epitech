/*
** EPITECH PROJECT, 2022
** pushswap_bubble_sort.c
** File description:
** pushswap_bubble_sort.c
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

static bool_t bubble_sort(pushswap_t *ps)
{
    bool_t has_swapped = false;

    for (u64_t i = 0; i + 1 < ps->l_a.length; i++) {
        if (*(u32_t *)deque_get(&ps->l_a, 0)
            > *(u32_t *)deque_get(&ps->l_a, 1)) {
            pushswap_apply_sa(ps);
            has_swapped = true;
        }
        pushswap_apply_ra(ps);
    }
    pushswap_apply_ra(ps);
    return has_swapped;
}

void pushswap_bubble_sort(pushswap_t *ps)
{
    for (bool_t sorted = is_sorted(&ps->l_a); !sorted;
        sorted = is_sorted(&ps->l_a))
        bubble_sort(ps);
}
