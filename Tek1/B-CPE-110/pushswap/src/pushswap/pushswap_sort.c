/*
** EPITECH PROJECT, 2022
** pushswap_sort.c
** File description:
** pushswap_sort.c
*/

#include "pushswap/pushswap.h"

void pushswap_sort(pushswap_t *ps)
{
    if (pushswap_simple(ps) == STATUS_SUCCESS)
        return;
    switch (ps->l_a.length) {
    case 2:
        pushswap_sort_2(ps);
        break;
    case 3:
        pushswap_sort_3(ps);
        break;
    case 4:
    case 5:
        pushswap_sort_4_5(ps);
        break;
    default:
        pushswap_radix_sort(ps);
    }
}
