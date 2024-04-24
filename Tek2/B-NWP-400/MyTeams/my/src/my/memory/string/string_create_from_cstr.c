/*
** EPITECH PROJECT, 2024
** string_create_from_cstr.c
** File description:
** string_create_from_cstr.c
*/

#include "my/memory/string.h"

#include <string.h>

string_t *string_create_from_cstr(const char *cstr)
{
    string_t *self = vec_create(sizeof(char));

    vec_push_back_some(self, cstr, strlen(cstr) + 1);
    return self;
}
