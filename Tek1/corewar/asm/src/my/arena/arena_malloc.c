/*
** EPITECH PROJECT, 2023
** arena_malloc.c
** File description:
** arena_malloc.c
*/

#include "my/arena_impl.h"

static region_t *find_suitable_region(arena_t *arena, size_t bytes)
{
    for (region_t *region = arena->regions; region; region = region->next) {
        if (region->length + bytes <= region->capacity)
            return region;
    }
    return NULL;
}

void *arena_malloc(arena_t *arena, size_t bytes)
{
    region_t *region = find_suitable_region(arena, bytes);

    if (region == NULL) {
        region = region_new(bytes);
        region->next = arena->regions;
        arena->regions = region;
    }
    region->length += bytes;
    return region->buffer + region->length - bytes;
}
