/*
** EPITECH PROJECT, 2022
** pushswap_simple.c
** File description:
** pushswap_simple.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/operations.h"

static void sort(pushswap_t *ps, u64_t offset)
{
    if (offset <= ps->l_a.length / 2) {
        for (u64_t i = 0; i < offset; i++)
            pushswap_apply_rra(ps);
    } else {
        for (u64_t i = 0; i < ps->l_a.length - offset; i++)
            pushswap_apply_ra(ps);
    }
}

status_t pushswap_simple(pushswap_t *ps)
{
    u64_t offset = 0;
    u8_t count = 0;

    for (u64_t i = 0; i + 1 < ps->l_a.length; i++) {
        if (*(u32_t *)deque_get(&ps->l_a, i) + 1
            == *(u32_t *)deque_get(&ps->l_a, i + 1)) {
            offset += count == 0;
        } else {
            count++;
        }
        if (count > 1)
            return STATUS_ERROR;
    }
    sort(ps, offset + 1);
    return STATUS_SUCCESS;
}
