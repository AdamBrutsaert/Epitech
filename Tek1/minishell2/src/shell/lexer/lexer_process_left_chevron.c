/*
** EPITECH PROJECT, 2023
** lexer_process_left_chevron.c
** File description:
** lexer_process_left_chevron.c
*/

#include "shell/lexer.h"

static bool lexer_process_double_left_chevron(lexer_t *lexer)
{
    char *value;

    reader_next(lexer->reader);
    value = reader_get_back(lexer->reader, 2);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_DOUBLE_LEFT_CHEVRON, value);
}

bool lexer_process_left_chevron(lexer_t *lexer)
{
    char *value;

    reader_next(lexer->reader);
    if (lexer_is_end(lexer))
        return false;
    if (reader_peek(lexer->reader) == '<')
        return lexer_process_double_left_chevron(lexer);
    value = reader_get_back(lexer->reader, 1);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_LEFT_CHEVRON, value);
}
