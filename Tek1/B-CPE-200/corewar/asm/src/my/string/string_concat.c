/*
** EPITECH PROJECT, 2023
** string_concat.c
** File description:
** string_concat.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_concat(arena_t *arena, string_t *string1, string_t *string2)
{
    string_t *new = string_new(arena);

    new->length = string1->length + string2->length;
    new->value = arena_malloc(arena, new->length);
    my_memcpy(new->value, string1->value, string1->length);
    my_memcpy(new->value + string1->length, string2->value, string2->length);
    return new;
}
