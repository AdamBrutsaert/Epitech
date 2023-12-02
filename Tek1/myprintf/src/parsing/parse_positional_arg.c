/*
** EPITECH PROJECT, 2022
** parse_positional_arg.c
** File description:
** Implementation of parse_positional_arg
*/

#include "my.h"
#include "parsing/parsing.h"

static char is_digit(char c)
{
    return c >= '0' && c <= '9';
}

void parse_positional_arg(context_t *ctx, format_resolution_t *format)
{
    uint32_t number = 0;
    char const *ptr = ctx->format;

    for (; is_digit(*ctx->format); ctx->format++)
        number = number * 10 + (*ctx->format - '0');
    if (is_digit(*ptr) && *ctx->format == '$') {
        if (number == 0)
            my_putstr_err("Error: argument position counts from 1.\n");
        format->value.index = number;
        ctx->format++;
    } else {
        ctx->format = ptr;
    }
}
