/*
** EPITECH PROJECT, 2023
** lexer_process_separator.c
** File description:
** lexer_process_separator.c
*/

#include "asm/lexer_impl.h"

bool lexer_process_separator(lexer_t *lexer, reader_t *reader)
{
    string_t *string = string_from_char(lexer->scratch, reader_next(reader, 1));

    lexer_push_token(lexer, reader, TOKEN_SEPARATOR, string);
    return true;
}
