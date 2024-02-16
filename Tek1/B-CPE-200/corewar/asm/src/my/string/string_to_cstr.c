/*
** EPITECH PROJECT, 2023
** string_to_cstr.c
** File description:
** string_to_cstr.c
*/

#include "my/string_impl.h"
#include "my/memory.h"

char *string_to_cstr(arena_t *arena, string_t *string)
{
    char *cstr = arena_malloc(arena, string->length + 1);

    my_memcpy(cstr, string->value, string->length);
    cstr[string->length] = '\0';
    return cstr;
}
