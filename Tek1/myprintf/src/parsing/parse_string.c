/*
** EPITECH PROJECT, 2022
** parse_string.c
** File description:
** Implementation of parse_string
*/

#include "parsing/parsing.h"

void parse_string(context_t *ctx)
{
    for (; *ctx->format; ctx->format++) {
        if (*ctx->format == '%')
            parse_format(ctx);
    }
    resolve_arguments(ctx);
    resolve_formats(ctx);
}
