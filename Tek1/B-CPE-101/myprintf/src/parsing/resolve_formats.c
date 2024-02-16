/*
** EPITECH PROJECT, 2022
** resolve_specification.c
** File description:
** Implementation of resolve_specification
*/

#include "parsing/parsing.h"

// TODO if width.resolve && width.index == 0, it is an error
// TODO if precision.resolve && precision.index == 0, it is an error
void resolve_formats(context_t *ctx)
{
    format_resolution_t *format;

    for (uint32_t i = 0; i < ctx->formats_array->length; i++) {
        format = &ctx->formats_array->formats[i];
        if (CONVERSION_TOKENS[format->conversion] == '%'
            || CONVERSION_TOKENS[format->conversion] == 0)
            continue;
        if (format->width.resolve) {
            format->width.resolve = 0;
            format->width.index =
                ctx->args_array->args[format->width.index].index;
        }
        if (format->precision.resolve) {
            format->precision.resolve = 0;
            format->precision.index =
                ctx->args_array->args[format->precision.index].index;
        }
        format->value.resolve = 0;
        format->value.index = ctx->args_array->args[format->value.index].index;
    }
}
