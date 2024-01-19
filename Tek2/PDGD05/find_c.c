/*
** EPITECH PROJECT, 2024
** find_c.c
** File description:
** find_c.c
*/

#include "string.h"

#include <stdbool.h>
#include <string.h>

static bool match(char *haystack, const char *needle, size_t length)
{
    return strncmp(haystack, needle, length) == 0;
}

int find_c(const string_t *self, const char *str, size_t pos)
{
    size_t self_len;
    size_t str_len;

    if (self->str == NULL || str == NULL)
        return -1;
    self_len = strlen(self->str);
    str_len = strlen(str);
    for (size_t i = pos; i < self_len; i++) {
        if (match(&self->str[i], str, str_len))
            return i;
    }
    return -1;
}
