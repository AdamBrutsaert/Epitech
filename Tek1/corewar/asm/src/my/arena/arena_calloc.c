/*
** EPITECH PROJECT, 2023
** arena_calloc.c
** File description:
** arena_calloc.c
*/

#include "my/arena_impl.h"
#include "my/memory.h"

void *arena_calloc(arena_t *arena, size_t bytes)
{
    return my_memset(arena_malloc(arena, bytes), 0, bytes);
}
