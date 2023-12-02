/*
** EPITECH PROJECT, 2022
** pushswap_create.c
** File description:
** pushswap_create.c
*/

#include "pushswap/pushswap.h"
#include "my/memory.h"

status_t pushswap_create(pushswap_t *ps)
{
    my_memset(&ps->l_a, 0, sizeof(deque_t));
    my_memset(&ps->l_b, 0, sizeof(deque_t));

    vector_create(&ps->operations, sizeof(u8_t));
    if (deque_create(&ps->l_a, sizeof(u32_t)) == STATUS_ERROR)
        return STATUS_ERROR;
    if (deque_create(&ps->l_b, sizeof(u32_t)) == STATUS_ERROR)
        return STATUS_ERROR;
    return STATUS_SUCCESS;
}
