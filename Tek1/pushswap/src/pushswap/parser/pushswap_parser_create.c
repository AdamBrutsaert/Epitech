/*
** EPITECH PROJECT, 2022
** pushswap_parser_create.c
** File description:
** pushswap_parser_create.c
*/

#include "pushswap/pushswap_parser.h"

static uint64_t get_operations_size(u32_t length)
{
    uint64_t log = length == 0;
    uint64_t count = length;

    for (; count; count /= 2)
        log++;
    return 2 * length * log + 1;
}

status_t pushswap_parser_create(pushswap_parser_t *parser, pushswap_t *ps,
    u32_t length)
{
    parser->ps = ps;
    vector_create(&parser->numbers, sizeof(number_t));
    vector_create(&parser->sorted, sizeof(number_t *));
    if (vector_reserve(&parser->numbers, length) == STATUS_ERROR
        || vector_reserve(&parser->sorted, length) == STATUS_ERROR
        || deque_reserve(&ps->l_a, length) == STATUS_ERROR
        || deque_reserve(&ps->l_b, length) == STATUS_ERROR
        || vector_reserve(&ps->operations, get_operations_size(length))
            == STATUS_ERROR)
        return STATUS_ERROR;
    return STATUS_SUCCESS;
}
