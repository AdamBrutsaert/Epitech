/*
** EPITECH PROJECT, 2023
** string_from.c
** File description:
** string_from.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_from(arena_t *arena, const char *value)
{
    string_t *string = string_new(arena);

    string->length = my_strlen(value);
    string->value = my_memcpy(
        arena_malloc(arena, string->length),
        value,
        string->length
    );
    return string;
}
