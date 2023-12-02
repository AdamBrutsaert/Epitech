/*
** EPITECH PROJECT, 2022
** pushwap_parser.h
** File description:
** pushwap_parser.h
*/

#pragma once

#include "pushswap.h"

typedef struct {
    i32_t value;
    u32_t index;
} number_t;

typedef struct {
    pushswap_t *ps;
    vector_t numbers;
    vector_t sorted;
} pushswap_parser_t;

status_t pushswap_parse(pushswap_t *ps, int argc, char **argv);

status_t pushswap_parser_create(pushswap_parser_t *parser, pushswap_t *ps,
    u32_t length);
void pushswap_parser_destroy(pushswap_parser_t *parser);

status_t pushswap_parse_arguments(pushswap_parser_t *parser, int argc,
    char **argv);
void pushswap_parser_sort(pushswap_parser_t *parser);
void pushswap_parser_process(pushswap_parser_t *parser);
