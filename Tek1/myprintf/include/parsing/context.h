/*
** EPITECH PROJECT, 2022
** context.h
** File description:
** Header of context
*/

#pragma once

#include <stdarg.h>

#include "format.h"
#include "argument.h"
#include "variant.h"

typedef struct {
    char const *format;
    va_list ap;
    uint32_t current_arg;
    format_resolution_array_t *formats_array;
    argument_array_t *args_array;
    variant_array_t *vars_array;
} context_t;

void context_create(context_t *ctx, char const *format);
void context_destroy(context_t *ctx);
