/*
** EPITECH PROJECT, 2022
** pushswap_parser_destroy.c
** File description:
** pushswap_parser_destroy.c
*/

#include "pushswap/pushswap_parser.h"

void pushswap_parser_destroy(pushswap_parser_t *parser)
{
    vector_destroy(&parser->numbers);
    vector_destroy(&parser->sorted);
}
