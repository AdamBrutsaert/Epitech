/*
** EPITECH PROJECT, 2023
** lexer_process_newline.c
** File description:
** lexer_process_newline.c
*/

#include "shell/lexer_impl.h"

bool lexer_process_newline(lexer_t *lexer, reader_t *reader)
{
    reader_next(reader);
    return lexer_push_token(lexer, reader, TOKEN_NEWLINE, 1);
}
