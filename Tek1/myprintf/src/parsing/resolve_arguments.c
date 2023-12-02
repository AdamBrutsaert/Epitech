/*
** EPITECH PROJECT, 2022
** resolve_arguments.c
** File description:
** Implementation of resolve_arguments
*/

#include "parsing/parsing.h"
#include "my.h"

static void resolve_arguments_part4(context_t *ctx, variant_t *var)
{
    switch (var->type) {
        case TYPE_WSTRING:
            var->value.as_wstring = va_arg(ctx->ap, wchar_t const *);
            break;
        case TYPE_CHAR_POINTER:
        case TYPE_POINTER:
            var->value.as_pointer = va_arg(ctx->ap, void *);
            break;
        case TYPE_PTRDIFF:
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, ptrdiff_t);
            break;
        case TYPE_SSIZE:
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, ssize_t);
            break;
        default:
            my_putstr_err("Error: you are not using an argument.\n");
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, int);
    }
}

static void resolve_arguments_part3(context_t *ctx, variant_t *var)
{
    switch (var->type) {
        case TYPE_INT_MAX:
            var->value.as_int_max = va_arg(ctx->ap, intmax_t);
            break;
        case TYPE_UNSIGNED_INT_MAX:
            var->value.as_unsigned_int_max = va_arg(ctx->ap, uintmax_t);
            break;
        case TYPE_DOUBLE:
            var->value.as_long_double = (long double)va_arg(ctx->ap, double);
            break;
        case TYPE_LONG_DOUBLE:
            var->value.as_long_double = va_arg(ctx->ap, long double);
            break;
        case TYPE_STRING:
            var->value.as_string = va_arg(ctx->ap, char const *);
            break;
        default:
            resolve_arguments_part4(ctx, var);
    }
}

static void resolve_arguments_part2(context_t *ctx, variant_t *var)
{
    switch (var->type) {
        case TYPE_UNSIGNED_LONG_INT:
            var->value.as_unsigned_int_max =
                (uintmax_t)va_arg(ctx->ap, unsigned long int);
            break;
        case TYPE_LONG_LONG_INT:
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, long long int);
            break;
        case TYPE_UNSIGNED_LONG_LONG_INT:
            var->value.as_unsigned_int_max =
                (uintmax_t)va_arg(ctx->ap, unsigned long long int);
            break;
        case TYPE_SIZE:
            var->value.as_unsigned_int_max =
                (uintmax_t)va_arg(ctx->ap, size_t);
            break;
        default:
            resolve_arguments_part3(ctx, var);
    }
}

static void resolve_arguments_part1(context_t *ctx, variant_t *var)
{
    switch (var->type) {
        case TYPE_CHAR:
        case TYPE_SHORT:
        case TYPE_INT:
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, int);
            break;
        case TYPE_UNSIGNED_CHAR:
        case TYPE_UNSIGNED_SHORT:
        case TYPE_UNSIGNED_INT:
        case TYPE_WINT:
            var->value.as_unsigned_int_max =
                (uintmax_t)va_arg(ctx->ap, unsigned int);
            break;
        case TYPE_LONG_INT:
            var->value.as_int_max = (intmax_t)va_arg(ctx->ap, long int);
            break;
        default:
            resolve_arguments_part2(ctx, var);
    }
}

void resolve_arguments(context_t *ctx)
{
    variant_t var;
    argument_array_t *array = ctx->args_array;

    for (uint32_t i = 1; i < array->length; i++) {
        var.type = array->args[i].type;
        resolve_arguments_part1(ctx, &var);
        array->args[i].index = variant_array_push(ctx->vars_array, &var);
    }
}
