/*
** EPITECH PROJECT, 2023
** string_from_char.c
** File description:
** string_from_char.c
*/

#include "my/string_impl.h"

string_t *string_from_char(arena_t *arena, char character)
{
    string_t *string = string_new(arena);

    string->length = 1;
    string->value = arena_malloc(arena, 1);
    string->value[0] = character;
    return string;
}
