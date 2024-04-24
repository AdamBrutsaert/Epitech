/*
** EPITECH PROJECT, 2024
** reader_lex.c
** File description:
** reader_lex.c
*/

#include "parsing/reader.h"

#include <stdio.h>

static bool is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\r';
}

static bool produce_argument(reader_t *reader, token_t **token)
{
    size_t len = 0;
    string_t *value;

    reader_pop(reader);
    while (reader_peek(reader) != '"' && reader_peek(reader) != '\0') {
        reader_pop(reader);
        len++;
    }
    if (reader_peek(reader) == '\0') {
        printf("[lexer] Unterminated string\n");
        return false;
    }
    value = reader_get_last_characters(reader, len);
    reader_pop(reader);
    *token = token_create(TOKEN_TYPE_ARGUMENT, value);
    string_destroy(value);
    return true;
}

static bool produce_string(reader_t *reader, token_t **token)
{
    size_t len = 0;
    string_t *value;

    while (!is_space(reader_peek(reader)) && reader_peek(reader) != '\n'
        && reader_peek(reader) != '\0') {
        reader_pop(reader);
        len++;
    }
    value = reader_get_last_characters(reader, len);
    *token = token_create(TOKEN_TYPE_STRING, value);
    string_destroy(value);
    return true;
}

static bool produce_slash(reader_t *reader, token_t **token)
{
    string_t *value;

    reader_pop(reader);
    value = reader_get_last_characters(reader, 1);
    *token = token_create(TOKEN_TYPE_SLASH, value);
    string_destroy(value);
    return true;
}

static bool produce_newline(reader_t *reader, token_t **token)
{
    string_t *value;

    reader_pop(reader);
    value = reader_get_last_characters(reader, 1);
    *token = token_create(TOKEN_TYPE_NEWLINE, value);
    string_destroy(value);
    return true;
}

bool reader_lex(reader_t *reader, token_t **token)
{
    while (is_space(reader_peek(reader)))
        reader_pop(reader);
    if (reader_peek(reader) == '\0')
        return false;
    if (reader_peek(reader) == '/')
        return produce_slash(reader, token);
    if (reader_peek(reader) == '"')
        return produce_argument(reader, token);
    if (reader_peek(reader) == '\n')
        return produce_newline(reader, token);
    return produce_string(reader, token);
}
