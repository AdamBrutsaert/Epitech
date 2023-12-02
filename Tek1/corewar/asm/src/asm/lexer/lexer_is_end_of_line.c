/*
** EPITECH PROJECT, 2023
** lexer_is_end_of_line.c
** File description:
** lexer_is_end_of_line.c
*/

#include "asm/lexer_impl.h"

bool lexer_is_end_of_line(lexer_t *lexer)
{
    return lexer_peek_type(lexer, 0) == TOKEN_NEWLINE
        || lexer_peek_type(lexer, 0) == TOKEN_EOF;
}
