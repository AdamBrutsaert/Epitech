/*
** EPITECH PROJECT, 2023
** arena_delete.c
** File description:
** arena_delete.c
*/

#include "my/arena_impl.h"
#include "my/memory.h"

void region_delete(region_t *region)
{
    if (region == NULL)
        return;
    region_delete(region->next);
    my_free(region->buffer);
    my_free(region);
}

void arena_delete(arena_t *arena)
{
    region_delete(arena->regions);
    my_free(arena);
}
