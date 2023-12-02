/*
** EPITECH PROJECT, 2023
** arena.h
** File description:
** arena.h
*/

#pragma once

#include <stddef.h>

typedef struct arena arena_t;

arena_t *arena_new(void);
void arena_delete(arena_t *arena);

void arena_clear(arena_t *arena);
void *arena_malloc(arena_t *arena, size_t bytes);
void *arena_calloc(arena_t *arena, size_t bytes);
