/*
** EPITECH PROJECT, 2024
** substr.c
** File description:
** substr.c
*/

#include "string.h"

#include <string.h>
#include <stdlib.h>

string_t *substr(const string_t *self, int offset, int length)
{
    int begin = offset;
    size_t str_length;
    string_t *new_str;
    char *str;

    if (self->str == NULL)
        return NULL;
    if (length < 0) {
        begin += length;
        length = -length;
    }
    str_length = strlen(self->str);
    while (begin < 0)
        begin += str_length;
    str = strndup(self->str + begin, length);
    new_str = malloc(sizeof(string_t));
    if (new_str != NULL)
        string_init(new_str, str);
    free(str);
    return new_str;
}
