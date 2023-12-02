/*
** EPITECH PROJECT, 2022
** context.c
** File description:
** Implementation of context
*/

#include "parsing/context.h"

void context_create(context_t *ctx, char const *format)
{
    ctx->format = format;
    ctx->current_arg = 1;
    ctx->formats_array = format_resolution_array_create();
    ctx->args_array = argument_array_create();
    ctx->vars_array = variant_array_create();
}

void context_destroy(context_t *ctx)
{
    format_resolution_array_destroy(ctx->formats_array);
    argument_array_destroy(ctx->args_array);
    variant_array_destroy(ctx->vars_array);
}
