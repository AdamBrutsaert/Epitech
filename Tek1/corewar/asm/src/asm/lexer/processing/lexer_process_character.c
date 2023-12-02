/*
** EPITECH PROJECT, 2023
** lexer_process_character.c
** File description:
** lexer_process_character.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_process_character(lexer_t *lexer, reader_t *reader)
{
    char c = reader_peek(reader, 0);

    if (lexer_is_command(lexer, reader))
        return lexer_process_command(lexer, reader);
    if (c == COMMENT_CHAR)
        return lexer_process_comment(lexer, reader);
    if (c == ' ' || c == '\t')
        return lexer_process_whitespace(lexer, reader);
    if (c == '\n')
        return lexer_process_newline(lexer, reader);
    if (c == '"')
        return lexer_process_string(lexer, reader);
    if (c == SEPARATOR_CHAR)
        return lexer_process_separator(lexer, reader);
    if (c == DIRECT_CHAR)
        return lexer_process_direct(lexer, reader);
    if (c == LABEL_CHAR)
        return lexer_process_indirect_label(lexer, reader);
    return lexer_process_default(lexer, reader);
}
