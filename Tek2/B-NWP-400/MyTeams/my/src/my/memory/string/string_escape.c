/*
** EPITECH PROJECT, 2024
** string_escape.c
** File description:
** string_escape.c
*/

#include "my/memory/string.h"

void string_escape(string_t *self, char character)
{
    for (size_t i = 0; i < STRING_LEN(self); i++) {
        if (STRING_AT(self, i) == character) {
            string_insert_cstr(self, i, "\\");
            i += 1;
        }
    }
}
