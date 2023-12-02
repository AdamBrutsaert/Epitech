/*
** EPITECH PROJECT, 2023
** token.h
** File description:
** token.h
*/

#pragma once

typedef struct token token_t;

typedef enum {
    TOKEN_LEFT_CHEVRON = 0,
    TOKEN_RIGHT_CHEVRON,
    TOKEN_DOUBLE_LEFT_CHEVRON,
    TOKEN_DOUBLE_RIGHT_CHEVRON,
    TOKEN_PIPE,
    TOKEN_DOUBLE_PIPE,
    TOKEN_DOUBLE_AMPERSAND,
    TOKEN_SEMICOLON,
    TOKEN_STRING,
    TOKEN_NEWLINE,
    TOKEN_END,
} token_type_t;

token_t *token_new(token_type_t type, char *value);
void token_delete(token_t *token);

token_type_t token_get_type(token_t *token);
char *token_get_value(token_t *token);

// Debug
void token_print(token_t *token);
