/*
** EPITECH PROJECT, 2024
** string_split_escaped.c
** File description:
** string_split_escaped.c
*/

#include "my/memory/string.h"

static bool check_escaped(char character, bool *escaped, char delimiter)
{
    if (*escaped && character == delimiter) {
        *escaped = false;
        return true;
    }
    if (*escaped) {
        *escaped = false;
        return false;
    }
    if (character == '\\') {
        *escaped = true;
        return true;
    }
    return false;
}

static string_t *get_string(
    const string_t *self,
    size_t start,
    size_t end,
    char del
)
{
    string_t *str = string_create_from_buffer(
        STRING_CDATA(self) + start,
        end - start
    );

    for (size_t i = STRING_LEN(str); i > 1; i--) {
        if (STRING_AT(str, i - 2) == '\\' && STRING_AT(str, i - 1) == del) {
            string_remove(str, i - 2, 1);
            i -= 1;
        }
    }
    return str;
}

vec_t *string_split_escaped(const string_t *self, char delimiter)
{
    vec_t *vec = vec_create(sizeof(string_t *));
    size_t start = 0;
    bool escaped = false;

    for (size_t end = 0; end < STRING_LEN(self); end++) {
        if (check_escaped(STRING_AT(self, end), &escaped, delimiter))
            continue;
        if (STRING_AT(self, end) != delimiter)
            continue;
        vec_push_back(vec, &(string_t *){get_string(self, start, end,
            delimiter)});
        start = end + 1;
    }
    vec_push_back(vec, &(string_t *){get_string(self, start, STRING_LEN(self),
        delimiter)});
    return vec;
}
