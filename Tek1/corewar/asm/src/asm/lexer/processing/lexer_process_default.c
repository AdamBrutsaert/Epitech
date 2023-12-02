/*
** EPITECH PROJECT, 2023
** lexer_process_default.c
** File description:
** lexer_process_default.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

static bool is_valid_character(char c)
{
    return c != ' '
        && c != '\t'
        && c != '\n'
        && c != '\0'
        && c != '"'
        && c != COMMENT_CHAR
        && c != SEPARATOR_CHAR
        && c != LABEL_CHAR
        && c != DIRECT_CHAR;
}

bool lexer_process_default(lexer_t *lexer, reader_t *reader)
{
    string_t *str = string_new(lexer->scratch);
    char *cstr;

    while (is_valid_character(reader_peek(reader, 0)))
        str = string_append_char(lexer->scratch, str, reader_next(reader, 1));
    if (reader_peek(reader, 0) == LABEL_CHAR) {
        str = string_append_char(lexer->scratch, str, reader_next(reader, 1));
        return lexer_process_label(lexer, reader, str);
    }
    if (lexer_is_indirect_value(str))
        return lexer_process_indirect_value(lexer, reader, str);
    if (lexer_is_register(str))
        return lexer_process_register(lexer, reader, str);
    cstr = string_to_cstr(lexer->scratch, str);
    if (lexer_is_instruction(cstr))
        return lexer_process_instruction(lexer, reader, str);
    lexer_error_token(lexer, reader, cstr);
    return false;
}
