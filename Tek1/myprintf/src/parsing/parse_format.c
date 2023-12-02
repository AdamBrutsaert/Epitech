/*
** EPITECH PROJECT, 2022
** parse_format.c
** File description:
** Implementation of parse_format
*/

#include "parsing/parsing.h"

void parse_format(context_t *ctx)
{
    format_resolution_t format = {0, 0, {0, 0}, {0, 0}, {1, 0}, 0, 0, 0};
    char const *ptr = ctx->format + 1;

    ctx->format++;
    parse_positional_arg(ctx, &format);
    parse_character_flag(ctx, &format);
    parse_width(ctx, &format);
    parse_precision(ctx, &format);
    parse_length_modifier(ctx, &format);
    parse_conversion(ctx, &format);
    format.length = (format.error == 0) * (ctx->format - ptr + 1);
    format_resolution_array_push(ctx->formats_array, &format);
}
