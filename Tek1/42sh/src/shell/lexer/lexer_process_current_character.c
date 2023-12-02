/*
** EPITECH PROJECT, 2023
** lexer_process_current_character.c
** File description:
** lexer_process_current_character.c
*/

#include "shell/lexer_impl.h"

bool lexer_process_current_character(lexer_t *lexer, reader_t *reader)
{
    char character = reader_peek(reader, 0);

    if (character == ' ' || character == '\t')
        return lexer_process_whitespace(lexer, reader);
    if (character == '<')
        return lexer_process_left_chevron(lexer, reader);
    if (character == '>')
        return lexer_process_right_chevron(lexer, reader);
    if (character == '|')
        return lexer_process_pipe(lexer, reader);
    if (character == '&' && reader_peek(reader, 1) == '&')
        return lexer_process_double_ampersand(lexer, reader);
    if (character == ';')
        return lexer_process_semicolon(lexer, reader);
    if (character == '\n')
        return lexer_process_newline(lexer, reader);
    return lexer_process_default(lexer, reader);
}
