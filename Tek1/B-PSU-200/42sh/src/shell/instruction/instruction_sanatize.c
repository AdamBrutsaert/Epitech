/*
** EPITECH PROJECT, 2023
** instruction_sanatize.c
** File description:
** instruction_sanatize.c
*/

#include "shell/instruction_impl.h"

// Dear programmer:
// When I wrote this code, only God and I knew how it worked.
// Now, only God knows it!

static bool check_quote(
    bool is_escaping,
    bool *inside_simple_quote,
    bool *inside_double_quote,
    char character
)
{
    if (character == '\'' && !(*inside_double_quote) && !is_escaping) {
        *inside_simple_quote = !(*inside_simple_quote);
        return true;
    }
    if (character == '"' && !(*inside_simple_quote) && !is_escaping) {
        *inside_double_quote = !(*inside_double_quote);
        return true;
    }
    return false;
}

char *instruction_sanatize(char *string)
{
    bool inside_simple_quote = false;
    bool inside_double_quote = false;
    bool is_escaping = false;
    bool is_quote = false;
    size_t i = 0;

    for (size_t j = 0; string[j]; j++) {
        is_quote = check_quote(is_escaping, &inside_simple_quote,
            &inside_double_quote, string[j]);
        is_escaping = (!inside_simple_quote && !inside_double_quote
            && string[j] == '\\');
        if ((!is_quote && !inside_simple_quote && !inside_double_quote
            && !is_escaping) || (inside_simple_quote && string[j] != '\'')
            || (inside_double_quote && string[j] != '"')) {
            string[i] = string[j];
            i++;
        }
    }
    string[i] = '\0';
    return string;
}
