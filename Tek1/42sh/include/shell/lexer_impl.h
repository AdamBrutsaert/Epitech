/*
** EPITECH PROJECT, 2023
** lexer_impl.h
** File description:
** lexer_impl.h
*/

#pragma once

#include "lexer.h"
#include "my/vector.h"

struct lexer {
    vec_t *tokens;
    size_t cursor;
};

bool lexer_push_token(
    lexer_t *lexer,
    reader_t *reader,
    token_type_t type,
    size_t length
);

bool lexer_process_current_character(lexer_t *lexer, reader_t *reader);
bool lexer_process_whitespace(lexer_t *lexer, reader_t *reader);
bool lexer_process_left_chevron(lexer_t *lexer, reader_t *reader);
bool lexer_process_right_chevron(lexer_t *lexer, reader_t *reader);
bool lexer_process_pipe(lexer_t *lexer, reader_t *reader);
bool lexer_process_double_ampersand(lexer_t *lexer, reader_t *reader);
bool lexer_process_semicolon(lexer_t *lexer, reader_t *reader);
bool lexer_process_newline(lexer_t *lexer, reader_t *reader);
bool lexer_process_default(lexer_t *lexer, reader_t *reader);
