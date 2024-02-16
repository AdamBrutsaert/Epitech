/*
** EPITECH PROJECT, 2022
** parsing.h
** File description:
** Header of parsing
*/

#pragma once

#include "context.h"

void parse_string(context_t *ctx);

void parse_format(context_t *ctx);
void parse_positional_arg(context_t *ctx, format_resolution_t *format);
void parse_character_flag(context_t *ctx, format_resolution_t *format);
void parse_width(context_t *ctx, format_resolution_t *format);
void parse_precision(context_t *ctx, format_resolution_t *format);
void parse_length_modifier(context_t *ctx, format_resolution_t *format);
void parse_conversion(context_t *ctx, format_resolution_t *format);

void resolve_arguments(context_t *ctx);
void resolve_formats(context_t *ctx);
