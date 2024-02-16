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
    arena_t *scratch;
    arena_t *arena;
    const char *filename;
};

// Breakpoints
typedef size_t breakpoint_t;

breakpoint_t lexer_create_breakpoint(lexer_t *lexer);
void lexer_restore_breakpoint(lexer_t *lexer, breakpoint_t breakpoint);

// Utilities
void lexer_push_token(
    lexer_t *lexer,
    reader_t *reader,
    token_type_t type,
    string_t *string
);

// Errors
void lexer_error(lexer_t *lexer, reader_t *reader, const char *msg);
void lexer_error_character(lexer_t *lexer, reader_t *reader, char c);
void lexer_error_token(lexer_t *lexer, reader_t *reader, const char *token);

// Processing
bool lexer_process_character(lexer_t *lexer, reader_t *reader);
bool lexer_process_default(lexer_t *lexer, reader_t *reader);
bool lexer_process_comment(lexer_t *lexer, reader_t *reader);
bool lexer_process_whitespace(lexer_t *lexer, reader_t *reader);
bool lexer_process_newline(lexer_t *lexer, reader_t *reader);
bool lexer_process_separator(lexer_t *lexer, reader_t *reader);
bool lexer_process_string(lexer_t *lexer, reader_t *reader);

bool lexer_process_direct(lexer_t *lexer, reader_t *reader);
bool lexer_process_direct_label(lexer_t *lexer, reader_t *reader);
bool lexer_process_direct_value(lexer_t *lexer, reader_t *reader);

bool lexer_is_indirect_value(string_t *string);
bool lexer_process_indirect_label(lexer_t *lexer, reader_t *reader);
bool lexer_process_indirect_value(
    lexer_t *lexer,
    reader_t *reader,
    string_t *string
);

bool lexer_process_instruction(
    lexer_t *lexer,
    reader_t *reader,
    string_t *string
);

bool lexer_process_register(lexer_t *lexer, reader_t *reader, string_t *string);
bool lexer_process_label(lexer_t *lexer, reader_t *reader, string_t *string);
bool lexer_process_command(lexer_t *lexer, reader_t *reader);

bool lexer_is_valid_end_character(char c);
bool lexer_is_command(lexer_t *lexer, reader_t *reader);
bool lexer_is_register(string_t *string);
bool lexer_is_instruction(const char *string);
