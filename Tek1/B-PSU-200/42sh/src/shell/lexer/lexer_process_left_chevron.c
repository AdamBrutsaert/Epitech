/*
** EPITECH PROJECT, 2023
** lexer_process_left_chevron.c
** File description:
** lexer_process_left_chevron.c
*/

#include "shell/lexer_impl.h"

bool lexer_process_left_chevron(lexer_t *lexer, reader_t *reader)
{
    reader_next(reader);
    if (reader_peek(reader, 0) == '<') {
        reader_next(reader);
        return lexer_push_token(lexer, reader, TOKEN_DOUBLE_LEFT_CHEVRON, 2);
    }
    return lexer_push_token(lexer, reader, TOKEN_LEFT_CHEVRON, 1);
}
