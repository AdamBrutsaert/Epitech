/*
** EPITECH PROJECT, 2023
** lexer_error_token.c
** File description:
** lexer_error_token.c
*/

#include "asm/lexer_impl.h"
#include "my/stdio.h"

void lexer_error_token(lexer_t *lexer, reader_t *reader, const char *token)
{
    my_eputcs("error: lexer: ");
    my_eputcs(lexer->filename);
    my_eputcs(": line ");
    my_eputu(reader_get_line_number(reader));
    my_eputcs(": invalid token '");
    my_eputcs(token);
    my_eputcs("'.\n");
}
