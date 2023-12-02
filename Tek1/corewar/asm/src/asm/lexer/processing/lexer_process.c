/*
** EPITECH PROJECT, 2023
** lexer_process.c
** File description:
** lexer_process.c
*/

#include "asm/lexer_impl.h"

bool lexer_process(lexer_t *lexer, reader_t *reader, const char *path)
{
    bool error = false;
    breakpoint_t breakpoint = lexer_create_breakpoint(lexer);

    lexer->filename = path;
    while (reader_peek(reader, 0) != '\0') {
        if (!lexer_process_character(lexer, reader)) {
            error = true;
            reader_skip_line(reader);
        }
        arena_clear(lexer->scratch);
    }
    if (error) {
        lexer_restore_breakpoint(lexer, breakpoint);
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_EOF, string_new(lexer->scratch));
    return true;
}
