/*
** EPITECH PROJECT, 2023
** lexer_process_pipe.c
** File description:
** lexer_process_pipe.c
*/

#include "shell/lexer.h"

bool lexer_process_pipe(lexer_t *lexer)
{
    char *value;

    reader_next(lexer->reader);
    value = reader_get_back(lexer->reader, 1);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_PIPE, value);
}
