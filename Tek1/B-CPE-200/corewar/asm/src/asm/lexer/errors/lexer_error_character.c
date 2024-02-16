/*
** EPITECH PROJECT, 2023
** lexer_error_character.c
** File description:
** lexer_error_character.c
*/

#include "asm/lexer_impl.h"
#include "my/stdio.h"

void lexer_error(lexer_t *lexer, reader_t *reader, const char *msg)
{
    my_eputcs("error: lexer: ");
    my_eputcs(lexer->filename);
    my_eputcs(": line ");
    my_eputu(reader_get_line_number(reader));
    my_eputcs(": ");
    my_eputcs(msg);
    my_eputcs(".\n");
}
