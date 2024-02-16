/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include "arena.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct string string_t;

string_t *string_new(arena_t *arena);
string_t *string_from(arena_t *arena, const char *value);
string_t *string_from_char(arena_t *arena, char character);

char string_get(string_t *string, size_t index);
char *string_get_raw(string_t *string);
size_t string_get_length(string_t *string);

char *string_to_cstr(arena_t *arena, string_t *string);
intmax_t string_to_int(string_t *string);

string_t *string_append_char(arena_t *arena, string_t *string, char value);
string_t *string_append(arena_t *arena, string_t *string, const char *value);
string_t *string_concat(arena_t *arena, string_t *string1, string_t *string2);
string_t *string_duplicate(arena_t *arena, string_t *string);
string_t *string_slice(arena_t *arena, string_t *str, size_t beg, size_t end);

bool string_equal(string_t *string1, string_t *string2);

// Old C API
size_t my_strlen(const char *string);
bool my_strcontains(const char *string, char character);
int16_t my_strncmp(const char *str1, const char *str2, size_t bytes);
int16_t my_strcmp(const char *str1, const char *str2);
char *my_strncpy(char *dest, const char *src, size_t bytes);
size_t my_strhash(const char *string);
