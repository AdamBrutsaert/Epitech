/*
** EPITECH PROJECT, 2023
** lexer_process_string.c
** File description:
** lexer_process_string.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

static size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}

bool lexer_process_string(lexer_t *lexer, reader_t *reader)
{
    string_t *string = string_from_char(lexer->scratch, reader_next(reader, 1));

    while (reader_peek(reader, 0) != '"') {
        if (reader_peek(reader, 0) == '\0' || reader_peek(reader, 0) == '\n') {
            lexer_error(lexer, reader, "unterminated string");
            return false;
        }
        string = string_append_char(
            lexer->scratch,
            string,
            reader_next(reader, 1)
        );
        if (string_get_length(string) > max(PROG_NAME_LENGTH, COMMENT_LENGTH)) {
            lexer_error(lexer, reader, "string too long");
            return false;
        }
    }
    string = string_append_char(lexer->scratch, string, reader_next(reader, 1));
    lexer_push_token(lexer, reader, TOKEN_STRING, string);
    return true;
}
