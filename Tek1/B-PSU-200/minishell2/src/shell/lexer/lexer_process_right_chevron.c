/*
** EPITECH PROJECT, 2023
** lexer_process_right_chevron.c
** File description:
** lexer_process_right_chevron.c
*/

#include "shell/lexer.h"

static bool lexer_process_double_right_chevron(lexer_t *lexer)
{
    char *value;

    reader_next(lexer->reader);
    value = reader_get_back(lexer->reader, 2);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_DOUBLE_RIGHT_CHEVRON, value);
}

bool lexer_process_right_chevron(lexer_t *lexer)
{
    char *value;

    reader_next(lexer->reader);
    if (lexer_is_end(lexer))
        return false;
    if (reader_peek(lexer->reader) == '>')
        return lexer_process_double_right_chevron(lexer);
    value = reader_get_back(lexer->reader, 1);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_RIGHT_CHEVRON, value);
}
