/*
** EPITECH PROJECT, 2023
** arena_impl.h
** File description:
** arena_impl.h
*/

#pragma once

#include "arena.h"

#define REGION_DEFAULT_CAPACITY (4 * 1024)

typedef struct region {
    void *buffer;
    size_t length;
    size_t capacity;
    struct region *next;
} region_t;

struct arena {
    region_t *regions;
};

region_t *region_new(size_t bytes);
