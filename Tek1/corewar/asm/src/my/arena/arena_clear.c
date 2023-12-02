/*
** EPITECH PROJECT, 2023
** arena_clear.c
** File description:
** arena_clear.c
*/

#include "my/arena_impl.h"
#include "my/memory.h"

void region_clear(region_t *region)
{
    if (region == NULL)
        return;
    region_clear(region->next);
    region->length = 0;
}

void arena_clear(arena_t *arena)
{
    region_clear(arena->regions);
}
