/*
** EPITECH PROJECT, 2023
** lexer_process_label.c
** File description:
** lexer_process_label.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

static bool is_valid_label(string_t *string)
{
    if (string_get_length(string) < 2)
        return false;
    for (size_t i = 0; i + 1 < string_get_length(string) ; i++) {
        if (!my_strcontains(LABEL_CHARS, string_get(string, i)))
            return false;
    }
    return true;
}

bool lexer_process_label(lexer_t *lexer, reader_t *reader, string_t *string)
{
    if (!is_valid_label(string)) {
        lexer_error(lexer, reader, "invalid label");
        return false;
    }
    if (!lexer_is_valid_end_character(reader_peek(reader, 0))) {
        lexer_error_character(lexer, reader, reader_peek(reader, 0));
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_LABEL, string);
    return true;
}
