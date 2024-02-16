/*
** EPITECH PROJECT, 2023
** lexer_is_end.c
** File description:
** lexer_is_end.c
*/

#include "shell/lexer.h"

bool lexer_is_end(lexer_t *lexer)
{
    return lexer->current >= lexer->length;
}
