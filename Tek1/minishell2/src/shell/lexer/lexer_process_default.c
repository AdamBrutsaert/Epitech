/*
** EPITECH PROJECT, 2023
** lexer_process_default.c
** File description:
** lexer_process_default.c
*/

#include "shell/lexer.h"
#include "my/stdio.h"

static bool on_quotes(lexer_t *lexer, char quote, size_t *length)
{
    reader_next(lexer->reader);
    (*length)++;
    while (reader_peek(lexer->reader) != quote) {
        if (reader_peek(lexer->reader) == '\0') {
            my_eputs("Unmatched '");
            my_eputc(quote);
            my_eputs("'.\n");
            return false;
        }
        reader_next(lexer->reader);
        (*length)++;
    }
    reader_next(lexer->reader);
    (*length)++;
    return true;
}

static bool is_end(lexer_t *lexer, bool *is_escaping)
{
    if (reader_is_end(lexer->reader))
        return true;
    if (*is_escaping) {
        *is_escaping = false;
        return false;
    }
    if (reader_peek(lexer->reader) == '\\') {
        *is_escaping = true;
        return false;
    }
    return reader_peek(lexer->reader) == ' '
        || reader_peek(lexer->reader) == '\t'
        || reader_peek(lexer->reader) == '\n'
        || reader_peek(lexer->reader) == ';'
        || reader_peek(lexer->reader) == '|'
        || reader_peek(lexer->reader) == '>'
        || reader_peek(lexer->reader) == '<';
}

static bool process_character(lexer_t *lexer, size_t *length)
{
    if (reader_peek(lexer->reader) == '\'')
        return on_quotes(lexer, '\'', length);
    if (reader_peek(lexer->reader) == '"')
        return on_quotes(lexer, '"', length);
    reader_next(lexer->reader);
    (*length)++;
    return true;
}

bool lexer_process_default(lexer_t *lexer)
{
    bool is_escaping = false;
    size_t length = 0;
    char *value;

    while (!is_end(lexer, &is_escaping)) {
        if (!process_character(lexer, &length))
            return false;
    }
    value = reader_get_back(lexer->reader, length);
    if (value == NULL)
        return false;
    return lexer_push(lexer, TOKEN_STRING, value);
}
