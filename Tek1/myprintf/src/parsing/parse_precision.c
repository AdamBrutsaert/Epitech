/*
** EPITECH PROJECT, 2022
** parse_precision.c
** File description:
** Implementation of parse_precision
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
    if (format->precision.resolve) {
        if (*ctx->format == '$' && !digit_count)
            my_putstr_err("Error: invalid argument position.\n");
        if (*ctx->format == '$' && digit_count && var->value.as_int_max) {
            format->precision.index = var->value.as_int_max;
        } else {
            format->precision.index = ctx->current_arg++;
        }
        if (*ctx->format == '$')
            ctx->format++;
        argument_array_set(ctx->args_array, format->precision.index, TYPE_INT);
    } else {
        format->precision.index = variant_array_push(ctx->vars_array, var);
    }
}

void parse_precision(context_t *ctx, format_resolution_t *format)
{
    variant_t var = {.type = TYPE_INT_MAX, .value.as_int_max = -1};
    int digit_count = 0;

    if (*ctx->format == '.') {
        var.value.as_int_max = 0;
        ctx->format++;
        if (*ctx->format == '*') {
            format->precision.resolve = 1;
            ctx->format++;
        }
        for (; is_digit(*ctx->format); ctx->format++) {
            var.value.as_int_max =
                var.value.as_int_max * 10 + (*ctx->format - '0');
            digit_count++;
        }
    }
    parse_argument(ctx, format, &var, digit_count);
}
