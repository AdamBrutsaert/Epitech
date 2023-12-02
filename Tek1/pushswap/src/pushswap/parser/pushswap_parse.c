/*
** EPITECH PROJECT, 2022
** pushswap_parse.c
** File description:
** pushswap_parse.c
*/

#include "pushswap/pushswap_parser.h"

status_t pushswap_parse(pushswap_t *ps, int argc, char **argv)
{
    pushswap_parser_t parser;

    if (pushswap_parser_create(&parser, ps, argc - 1) == STATUS_ERROR) {
        pushswap_parser_destroy(&parser);
        return STATUS_ERROR;
    }
    if (pushswap_parse_arguments(&parser, argc, argv) == STATUS_ERROR) {
        pushswap_parser_destroy(&parser);
        return STATUS_ERROR;
    }
    pushswap_parser_process(&parser);
    pushswap_parser_destroy(&parser);
    return STATUS_SUCCESS;
}
