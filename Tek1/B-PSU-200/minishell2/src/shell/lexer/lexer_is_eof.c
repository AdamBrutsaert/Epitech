/*
** EPITECH PROJECT, 2023
** lexer_is_eof.c
** File description:
** lexer_is_eof.c
*/

#include "shell/lexer.h"

bool lexer_is_eof(lexer_t *lexer)
{
    return reader_is_eof(lexer->reader);
}
