/*
** EPITECH PROJECT, 2023
** lexer_process_double_ampersand.c
** File description:
** lexer_process_double_ampersand.c
*/

#include "shell/lexer_impl.h"

bool lexer_process_double_ampersand(lexer_t *lexer, reader_t *reader)
{
    reader_next(reader);
    reader_next(reader);
    return lexer_push_token(lexer, reader, TOKEN_DOUBLE_AMPERSAND, 2);
}
