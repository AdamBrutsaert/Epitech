/*
** EPITECH PROJECT, 2023
** expression_split.c
** File description:
** expression_split.c
*/

#include "expression.h"
#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>

static bool is_whitespace(char character)
{
    return character == ' '
        || character == '\t'
        || character == '\r'
        || character == '\n';
}

static void check_character(
    bool *is_escaping,
    bool *inside_simple_quote,
    bool *inside_double_quote,
    char character
)
{
    if (character == '\'' && !(*inside_double_quote) && !(*is_escaping))
        *inside_simple_quote = !(*inside_simple_quote);
    if (character == '"' && !(*inside_simple_quote) && !(*is_escaping))
        *inside_double_quote = !(*inside_double_quote);
    *is_escaping = !(*inside_simple_quote)
        && !(*inside_double_quote)
        && character == '\\';
}

static uint64_t count_tokens(char const *string)
{
    uint64_t count = 0;
    bool inside_simple_quote = false;
    bool inside_double_quote = false;
    bool is_escaping = false;
    bool inside_token = false;

    for (; *string; string++) {
        if (inside_simple_quote || inside_double_quote
            || is_escaping || !is_whitespace(*string)) {
            count += !inside_token;
            inside_token = true;
        } else {
            inside_token = false;
        }
        check_character(&is_escaping, &inside_simple_quote,
            &inside_double_quote, *string);
    }
    return count;
}

static char *next(char const **string)
{
    char const *begin;
    bool inside_simple_quote = false;
    bool inside_double_quote = false;
    bool is_escaping = false;

    while (**string && is_whitespace(**string))
        (*string)++;
    begin = *string;
    for (; **string; (*string)++) {
        if (!(inside_simple_quote || inside_double_quote
            || is_escaping || !is_whitespace(**string)))
            break;
        if (**string == '\'' && !inside_double_quote && !is_escaping)
            inside_simple_quote = !inside_simple_quote;
        if (**string == '"' && !inside_simple_quote && !is_escaping)
            inside_double_quote = !inside_double_quote;
        is_escaping = !inside_simple_quote && !inside_double_quote
            && **string == '\\';
    }
    return my_strndup(begin, *string - begin);
}

char **expression_split(char const *string)
{
    uint64_t count = count_tokens(string);
    char **tokens = malloc(sizeof(char *) * (count + 1));

    if (tokens == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    tokens[count] = NULL;
    for (uint64_t i = 0; i < count; i++) {
        tokens[i] = next(&string);
        if (ERROR != OK) {
            my_strarrfree(tokens);
            THROW_NULL(ERROR);
        }
    }
    return tokens;
}
