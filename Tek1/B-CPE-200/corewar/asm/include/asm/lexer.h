/*
** EPITECH PROJECT, 2023
** lexer.h
** File description:
** lexer.h
*/

#pragma once

#include "reader.h"
#include "my/string.h"

typedef enum {
    // Instructions
    TOKEN_INSTRUCTION = 0,

    // Names
    TOKEN_COMMAND,
    TOKEN_LABEL,

    // Values
    TOKEN_REGISTER,
    TOKEN_DIRECT_VALUE,
    TOKEN_DIRECT_LABEL,
    TOKEN_INDIRECT_VALUE,
    TOKEN_INDIRECT_LABEL,
    TOKEN_STRING,

    // Separators
    TOKEN_SEPARATOR,
    TOKEN_NEWLINE,
    TOKEN_EOF
} token_type_t;

typedef struct {
    token_type_t type;
    string_t *value;
    size_t line;
} token_t;

typedef struct lexer lexer_t;

lexer_t *lexer_new(void);
void lexer_delete(lexer_t *lexer);

void lexer_clear(lexer_t *lexer);
bool lexer_process(lexer_t *lexer, reader_t *reader, const char *path);

void lexer_skip_newlines(lexer_t *lexer);
bool lexer_is_end_of_line(lexer_t *lexer);

token_t *lexer_peek(lexer_t *lexer, size_t offset);
token_type_t lexer_peek_type(lexer_t *lexer, size_t offset);
token_t *lexer_next(lexer_t *lexer);
string_t *lexer_next_value(lexer_t *lexer);

void lexer_debug(lexer_t *lexer);
