/*
** EPITECH PROJECT, 2023
** region_new.c
** File description:
** region_new.c
*/

#include "my/arena_impl.h"
#include "my/memory.h"

static size_t get_capacity(size_t bytes)
{
    size_t capacity = 1;

    if (bytes < REGION_DEFAULT_CAPACITY)
        return REGION_DEFAULT_CAPACITY;
    while (capacity < bytes && capacity < 65536)
        capacity *= 2;
    while (capacity < bytes)
        capacity += 65536;
    return capacity;
}

region_t *region_new(size_t bytes)
{
    region_t *region = my_malloc(sizeof(region_t));

    region->length = 0;
    region->capacity = get_capacity(bytes);
    region->buffer = my_malloc(region->capacity);
    region->next = NULL;
    return region;
}
