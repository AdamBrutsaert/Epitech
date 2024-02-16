/*
** EPITECH PROJECT, 2023
** string_append.c
** File description:
** string_append.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_append(arena_t *arena, string_t *string, const char *value)
{
    string_t *new = string_new(arena);
    size_t length = my_strlen(value);

    new->length = string->length + length;
    new->value = arena_malloc(arena, new->length);
    my_memcpy(new->value, string->value, string->length);
    my_memcpy(new->value + string->length, value, length);
    return new;
}
