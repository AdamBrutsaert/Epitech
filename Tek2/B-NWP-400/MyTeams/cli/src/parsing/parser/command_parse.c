/*
** EPITECH PROJECT, 2024
** parse.c
** File description:
** parse.c
*/

#include "parsing/parser.h"

#include <stdio.h>

static bool check_slash(reader_t *reader)
{
    token_t *token;

    if (!reader_lex(reader, &token))
        return false;
    if (token->type != TOKEN_TYPE_SLASH) {
        printf("[parser] Expected slash\n");
        token_destroy(token);
        return false;
    }
    token_destroy(token);
    return true;
}

static bool get_name(command_t *self, reader_t *reader)
{
    token_t *token;

    if (!reader_lex(reader, &token))
        return false;
    if (token->type != TOKEN_TYPE_STRING) {
        printf("[parser] Expected command name\n");
        token_destroy(token);
        return false;
    }
    string_destroy(self->name);
    self->name = string_clone(token->value);
    token_destroy(token);
    return true;
}

static bool get_arguments(command_t *self, reader_t *reader)
{
    token_t *token;
    string_t *arg;

    if (!reader_lex(reader, &token))
        return false;
    while (token->type == TOKEN_TYPE_ARGUMENT) {
        arg = string_clone(token->value);
        vec_push_back(self->arguments, &arg);
        token_destroy(token);
        if (!reader_lex(reader, &token))
            return false;
    }
    if (token->type != TOKEN_TYPE_NEWLINE) {
        printf("[parser] Expected zero or more args followed by a newline\n");
        token_destroy(token);
        return false;
    }
    token_destroy(token);
    return true;
}

bool command_parse(command_t *self, reader_t *reader)
{
    return check_slash(reader)
        && get_name(self, reader)
        && get_arguments(self, reader);
}
