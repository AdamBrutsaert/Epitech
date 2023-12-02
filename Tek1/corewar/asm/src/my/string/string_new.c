/*
** EPITECH PROJECT, 2023
** string_new.c
** File description:
** string_new.c
*/

#include "my/string_impl.h"

string_t *string_new(arena_t *arena)
{
    return arena_calloc(arena, sizeof(string_t));
}
