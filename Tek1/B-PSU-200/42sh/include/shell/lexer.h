/*
** EPITECH PROJECT, 2023
** lexer.h
** File description:
** lexer.h
*/

#pragma once

#include "token.h"
#include "reader.h"

typedef struct lexer lexer_t;

lexer_t *lexer_new(void);
void lexer_delete(lexer_t *lexer);

bool lexer_process(lexer_t *lexer, reader_t *reader);
void lexer_clear(lexer_t *lexer);

token_type_t lexer_peek_type(lexer_t *lexer, size_t n);
token_t *lexer_peek(lexer_t *lexer, size_t n);
token_t *lexer_next(lexer_t *lexer);

// Debug
void lexer_print(lexer_t *lexer);
