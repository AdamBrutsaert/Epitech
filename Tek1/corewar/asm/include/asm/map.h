/*
** EPITECH PROJECT, 2023
** map.h
** File description:
** map.h
*/

#pragma once

#include <stddef.h>

typedef struct map map_t;

map_t *map_new(void);
void map_delete(map_t *map);

void map_set(map_t *map, const char *key, size_t value);
size_t *map_get(map_t *map, const char *key);
