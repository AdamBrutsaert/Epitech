/*
** EPITECH PROJECT, 2023
** lexer_process.c
** File description:
** lexer_process.c
*/

#include "shell/lexer_impl.h"

static void skip_current_command(reader_t *reader)
{
    while (reader_peek(reader, 0) != '\n' && reader_peek(reader, 0) != '\0')
        reader_next(reader);
    reader_next(reader);
}

bool lexer_process(lexer_t *lexer, reader_t *reader)
{
    while (reader_peek(reader, 0) != '\0') {
        if (!lexer_process_current_character(lexer, reader)) {
            skip_current_command(reader);
            return false;
        }
    }
    if (!lexer_push_token(lexer, reader, TOKEN_END, 0)) {
        skip_current_command(reader);
        return false;
    }
    return true;
}
