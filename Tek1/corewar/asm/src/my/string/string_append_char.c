/*
** EPITECH PROJECT, 2023
** string_append_char.c
** File description:
** string_append_char.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_append_char(arena_t *arena, string_t *string, char value)
{
    string_t *new = string_new(arena);

    new->length = string->length + 1;
    new->value = arena_malloc(arena, new->length);
    my_memcpy(new->value, string->value, string->length);
    new->value[string->length] = value;
    return new;
}
