/*
** EPITECH PROJECT, 2023
** lexer_process_character.c
** File description:
** lexer_process_character.c
*/

#include "shell/lexer.h"

bool lexer_process_character(lexer_t *lexer)
{
    char character = reader_peek(lexer->reader);

    if (character == ' ' || character == '\t')
        return lexer_process_whitespace(lexer);
    if (character == '\n')
        return lexer_process_newline(lexer);
    if (character == '<')
        return lexer_process_left_chevron(lexer);
    if (character == '>')
        return lexer_process_right_chevron(lexer);
    if (character == '|')
        return lexer_process_pipe(lexer);
    if (character == ';')
        return lexer_process_semicolon(lexer);
    return lexer_process_default(lexer);
}
