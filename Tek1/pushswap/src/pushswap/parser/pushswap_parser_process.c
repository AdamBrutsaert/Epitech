/*
** EPITECH PROJECT, 2022
** pushswap_parser_process.c
** File description:
** pushswap_parser_process.c
*/

#include "pushswap/pushswap_parser.h"

void pushswap_parser_process(pushswap_parser_t *parser)
{
    pushswap_parser_sort(parser);
    for (u64_t i = 0; i < parser->sorted.length; i++) {
        ((number_t **)parser->sorted.values)[i]->index = i;
    }
    for (u64_t i = 0; i < parser->numbers.length; i++)
        deque_push_back(&parser->ps->l_a,
            &((number_t *)parser->numbers.values)[i].index);
}
