/*
** EPITECH PROJECT, 2023
** lexer_is_command.c
** File description:
** lexer_is_command.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_is_command(__attribute__((unused)) lexer_t *lexer, reader_t *reader)
{
    return reader_match(reader, NAME_CMD_STRING)
        || reader_match(reader, COMMENT_CMD_STRING);
}
