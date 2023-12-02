/*
** EPITECH PROJECT, 2023
** lexer.h
** File description:
** lexer.h
*/

#pragma once

#include "token.h"
#include "reader.h"

typedef struct {
    reader_t *reader;
    token_t *tokens;
    size_t length;
    size_t capacity;
    size_t current;
} lexer_t;

lexer_t *lexer_create(reader_t *reader);
void lexer_destroy(lexer_t *lexer);

void lexer_reset(lexer_t *lexer);
bool lexer_process(lexer_t *lexer);
bool lexer_process_character(lexer_t *lexer);
bool lexer_process_whitespace(lexer_t *lexer);
bool lexer_process_newline(lexer_t *lexer);
bool lexer_process_left_chevron(lexer_t *lexer);
bool lexer_process_right_chevron(lexer_t *lexer);
bool lexer_process_pipe(lexer_t *lexer);
bool lexer_process_semicolon(lexer_t *lexer);
bool lexer_process_default(lexer_t *lexer);

void lexer_debug(lexer_t *lexer);
bool lexer_is_eof(lexer_t *lexer);
bool lexer_is_end(lexer_t *lexer);
bool lexer_push(lexer_t *lexer, token_type_t type, char *value);
token_t *lexer_next(lexer_t *lexer);
token_t *lexer_peek(lexer_t *lexer);
