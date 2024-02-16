/*
** EPITECH PROJECT, 2023
** string_slice.c
** File description:
** string_slice.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

string_t *string_slice(arena_t *arena, string_t *str, size_t beg, size_t end)
{
    string_t *new = string_new(arena);

    new->value = arena_malloc(arena, end - beg);
    new->length = end - beg;
    my_memcpy(new->value, str->value + beg, new->length);
    return new;
}
