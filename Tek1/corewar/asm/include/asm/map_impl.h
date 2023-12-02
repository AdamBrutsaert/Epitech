/*
** EPITECH PROJECT, 2023
** map_impl.h
** File description:
** map_impl.h
*/

#pragma once

#include "map.h"
#include "my/arena.h"

#define MAP_SIZE 64

typedef struct map_node {
    char *key;
    size_t value;
    struct map_node *next;
} map_node_t;

struct map {
    map_node_t **nodes;
    arena_t *arena;
};

map_node_t *map_find_node(map_t *map, const char *key);
