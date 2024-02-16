/*
** EPITECH PROJECT, 2023
** arena_new.c
** File description:
** arena_new.c
*/

#include "my/arena_impl.h"
#include "my/memory.h"

arena_t *arena_new(void)
{
    arena_t *arena = my_calloc(sizeof(arena_t));

    arena->regions = region_new(REGION_DEFAULT_CAPACITY);
    return arena;
}
