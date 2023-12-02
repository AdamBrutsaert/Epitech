/*
** EPITECH PROJECT, 2022
** parse_character_flag.c
** File description:
** Implementation of parse_character_flag
*/

#include "parsing/parsing.h"

static char is_character_flag(char c)
{
    return c == '-' || c == '+' || c == ' ' || c == '0' || c == '#';
}

void parse_character_flag(context_t *ctx, format_resolution_t *format)
{
    for (; is_character_flag(*ctx->format); ctx->format++) {
        if (*ctx->format == '-')
            format->flags |= FLAG_LEFT_ADJUSTED;
        if (*ctx->format == '+')
            format->flags |= FLAG_SIGN;
        if (*ctx->format == ' ')
            format->flags |= FLAG_BLANK;
        if (*ctx->format == '0')
            format->flags |= FLAG_ZERO_PADDED;
        if (*ctx->format == '#')
            format->flags |= FLAG_ALTERNATE_FORM;
    }
}
