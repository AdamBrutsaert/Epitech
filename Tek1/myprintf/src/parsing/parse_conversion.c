/*
** EPITECH PROJECT, 2022
** parse_conversion.c
** File description:
** Implementation of parse_conversion.c
*/

#include "my.h"
#include "parsing/parsing.h"

static void set_arg(context_t *ctx, format_resolution_t *format)
{
    if (CONVERSION_TOKENS[format->conversion] != '%') {
        if (!format->value.index)
            format->value.index = ctx->current_arg++;
        argument_array_set(ctx->args_array, format->value.index,
            TOKENS_TO_TYPE[format->length_modifier][format->conversion]);
    }
}

void parse_conversion(context_t *ctx, format_resolution_t *format)
{
    int32_t i = 0;

    for (; CONVERSION_TOKENS[i]; i++) {
        if (*ctx->format == CONVERSION_TOKENS[i]) {
            format->conversion = i;
            set_arg(ctx, format);
            return;
        }
    }
    format->conversion = i;
    format->error = 1;
    my_putstr_err("Error: invalid or missing conversion specifier.\n");
}
