/*
** EPITECH PROJECT, 2022
** parse_width.c
** File description:
** Implementation of parse_width
*/

#include "my.h"
#include "parsing/parsing.h"

static char is_digit(char c)
{
    return c >= '0' && c <= '9';
}

static void parse_argument(context_t *ctx, format_resolution_t *format,
    variant_t *var, int digit_count)
{
    if (format->width.resolve) {
        if (*ctx->format == '$' && !digit_count)
            my_putstr_err("Error: invalid argument position.\n");
        if (*ctx->format == '$' && digit_count && var->value.as_int_max) {
            format->width.index = var->value.as_int_max;
        } else {
            format->width.index = ctx->current_arg++;
        }
        if (*ctx->format == '$')
            ctx->format++;
        argument_array_set(ctx->args_array, format->width.index, TYPE_INT);
    } else {
        format->width.index = variant_array_push(ctx->vars_array, var);
    }
}

void parse_width(context_t *ctx, format_resolution_t *format)
{
    variant_t var = {.type = TYPE_INT_MAX, .value.as_int_max = -1};
    int digit_count = 0;

    if (*ctx->format == '*') {
        format->width.resolve = 1;
        ctx->format++;
    }
    if (is_digit(*ctx->format))
        var.value.as_int_max = 0;
    for (; is_digit(*ctx->format); ctx->format++) {
        var.value.as_int_max =
            var.value.as_int_max * 10 + (*ctx->format - '0');
        digit_count++;
    }
    parse_argument(ctx, format, &var, digit_count);
}
