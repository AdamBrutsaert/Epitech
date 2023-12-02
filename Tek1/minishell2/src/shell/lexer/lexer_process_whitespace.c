/*
** EPITECH PROJECT, 2023
** lexer_process_whitespace.c
** File description:
** lexer_process_whitespace.c
*/

#include "shell/lexer.h"

bool lexer_process_whitespace(lexer_t *lexer)
{
    reader_next(lexer->reader);
    return true;
}
