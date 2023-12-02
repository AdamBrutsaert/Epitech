/*
** EPITECH PROJECT, 2023
** lexer_process_direct_label.c
** File description:
** lexer_process_direct_label.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_process_direct_label(lexer_t *lexer, reader_t *reader)
{
    string_t *str = string_from_char(lexer->scratch, reader_next(reader, 1));

    str = string_append_char(lexer->scratch, str, reader_next(reader, 1));
    while (my_strcontains(LABEL_CHARS, reader_peek(reader, 0)))
        str = string_append_char(lexer->scratch, str, reader_next(reader, 1));
    if (!lexer_is_valid_end_character(reader_peek(reader, 0))) {
        lexer_error_character(lexer, reader, reader_peek(reader, 0));
        return false;
    }
    if (string_get_length(str) == 2) {
        lexer_error(lexer, reader, "invalid direct label");
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_DIRECT_LABEL, str);
    return true;
}
