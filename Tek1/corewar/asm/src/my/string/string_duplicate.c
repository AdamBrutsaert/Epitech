/*
** EPITECH PROJECT, 2023
** string_duplicate.c
** File description:
** string_duplicate.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_duplicate(arena_t *arena, string_t *string)
{
    string_t *new = string_new(arena);

    new->length = string->length;
    new->value = arena_malloc(arena, new->length);
    my_memcpy(new->value, string->value, string->length);
    return new;
}
