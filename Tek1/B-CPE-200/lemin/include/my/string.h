/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

size_t my_strlen(const char *string);
char *my_strncpy(char *dest, const char *src, size_t bytes);
char *my_strndup(const char *string, size_t bytes);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *string);
int16_t my_strcmp(const char *s1, const char *s2);
size_t my_strhash(const char *string);
