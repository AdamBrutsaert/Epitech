/*
** EPITECH PROJECT, 2023
** lexer_error.c
** File description:
** lexer_error.c
*/

#include "asm/lexer_impl.h"
#include "my/stdio.h"

void lexer_error_character(lexer_t *lexer, reader_t *reader, char c)
{
    my_eputcs("error: lexer: ");
    my_eputcs(lexer->filename);
    my_eputcs(": line ");
    my_eputu(reader_get_line_number(reader));
    my_eputcs(": invalid character '");
    my_eputc(c);
    my_eputcs("'.\n");
};
