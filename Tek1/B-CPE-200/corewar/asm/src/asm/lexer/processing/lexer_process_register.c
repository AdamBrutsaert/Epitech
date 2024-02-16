/*
** EPITECH PROJECT, 2023
** lexer_process_register.c
** File description:
** lexer_process_register.c
*/

#include "asm/lexer_impl.h"

bool lexer_process_register(lexer_t *lexer, reader_t *reader, string_t *string)
{
    if (!lexer_is_valid_end_character(reader_peek(reader, 0))) {
        lexer_error_character(lexer, reader, reader_peek(reader, 0));
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_REGISTER, string);
    return true;
}
