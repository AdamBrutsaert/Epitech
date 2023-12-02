/*
** EPITECH PROJECT, 2023
** lexer_is_valid_end_character.c
** File description:
** lexer_is_valid_end_character.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_is_valid_end_character(char c)
{
    return c == ' '
        || c == '\t'
        || c == '\n'
        || c == '\0'
        || c == COMMENT_CHAR
        || c == SEPARATOR_CHAR;
}
