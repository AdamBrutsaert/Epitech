/*
** EPITECH PROJECT, 2023
** token.h
** File description:
** token.h
*/

#pragma once

#include <stdbool.h>

typedef enum {
    TOKEN_LEFT_CHEVRON,
    TOKEN_RIGHT_CHEVRON,
    TOKEN_DOUBLE_LEFT_CHEVRON,
    TOKEN_DOUBLE_RIGHT_CHEVRON,
    TOKEN_PIPE,
    TOKEN_STRING,
    TOKEN_SEMICOLON,
    TOKEN_NEWLINE,
    TOKEN_END,
} token_type_t;

typedef struct {
    token_type_t type;
    char *value;
} token_t;

void token_debug(token_t *token);
