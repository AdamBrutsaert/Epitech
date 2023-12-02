/*
** EPITECH PROJECT, 2022
** pushswap_destroy.c
** File description:
** pushswap_destroy.c
*/

#include "pushswap/pushswap.h"

void pushswap_destroy(pushswap_t *ps)
{
    deque_destroy(&ps->l_b);
    deque_destroy(&ps->l_a);
    vector_destroy(&ps->operations);
}
