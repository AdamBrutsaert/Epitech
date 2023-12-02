/*
** EPITECH PROJECT, 2023
** lexer_process_default.c
** File description:
** lexer_process_default.c
*/

#include "shell/lexer_impl.h"

#include <stdio.h>

static bool on_quotes(
    reader_t *reader,
    char quote,
    size_t *length
)
{
    reader_next(reader);
    (*length)++;
    while (reader_peek(reader, 0) != quote) {
        if (reader_peek(reader, 0) == '\0') {
            printf("Unmatched '%c'.\n", quote);
            return false;
        }
        reader_next(reader);
        (*length)++;
    }
    reader_next(reader);
    (*length)++;
    return true;
}

static bool is_end(reader_t *reader, bool *is_escaping)
{
    if (reader_peek(reader, 0) == '\0')
        return true;
    if (*is_escaping) {
        *is_escaping = false;
        return false;
    }
    if (reader_peek(reader, 0) == '\\') {
        *is_escaping = true;
        return false;
    }
    return reader_peek(reader, 0) == ' '
        || reader_peek(reader, 0) == '\t'
        || reader_peek(reader, 0) == '\n'
        || reader_peek(reader, 0) == ';'
        || reader_peek(reader, 0) == '|'
        || reader_peek(reader, 0) == '>'
        || reader_peek(reader, 0) == '<'
        || (reader_peek(reader, 0) == '&' && reader_peek(reader, 1) == '&');
}

static bool process_character(reader_t *reader, size_t *length)
{
    if (reader_peek(reader, 0) == '\'')
        return on_quotes(reader, '\'', length);
    if (reader_peek(reader, 0) == '"')
        return on_quotes(reader, '"', length);
    reader_next(reader);
    (*length)++;
    return true;
}

bool lexer_process_default(lexer_t *lexer, reader_t *reader)
{
    bool is_escaping = false;
    size_t length = 0;

    while (!is_end(reader, &is_escaping)) {
        if (!process_character(reader, &length))
            return false;
    }
    return lexer_push_token(lexer, reader, TOKEN_STRING, length);
}
