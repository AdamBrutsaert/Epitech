/*
** EPITECH PROJECT, 2022
** parse_length_modifier.c
** File description:
** Implementation of parse_length_modifier
*/

#include "parsing/parsing.h"
#include "my.h"

void parse_length_modifier(context_t *ctx, format_resolution_t *format)
{
    char const *token;
    int length;
    int32_t i = 0;

    for (; LENGTH_MODIFIER_TOKENS[i]; i++) {
        token = LENGTH_MODIFIER_TOKENS[i];
        length = my_strlen(token);
        if (!my_strncmp(token, ctx->format, length)) {
            format->length_modifier = i;
            ctx->format += length;
            return;
        }
    }
    format->length_modifier = i;
}
