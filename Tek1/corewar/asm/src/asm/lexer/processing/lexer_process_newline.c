/*
** EPITECH PROJECT, 2023
** lexer_process_newline.c
** File description:
** lexer_process_newline.c
*/

#include "asm/lexer_impl.h"

bool lexer_process_newline(lexer_t *lexer, reader_t *reader)
{
    string_t *string = string_from_char(lexer->scratch, reader_next(reader, 1));

    lexer_push_token(lexer, reader, TOKEN_NEWLINE, string);
    return true;
}
