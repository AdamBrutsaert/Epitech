/*
** EPITECH PROJECT, 2023
** lexer_process.c
** File description:
** lexer_process.c
*/

#include "shell/lexer.h"

bool lexer_process(lexer_t *lexer)
{
    lexer_reset(lexer);
    reader_read_line(lexer->reader);
    if (reader_is_eof(lexer->reader))
        return false;
    while (reader_peek(lexer->reader) != '\0') {
        if (!lexer_process_character(lexer))
            return false;
    }
    reader_next(lexer->reader);
    return lexer_push(lexer, TOKEN_END, NULL);
}
