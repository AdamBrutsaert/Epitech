/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include <stddef.h>
#include <stdint.h>

char **my_strsplit(const char *string, char delimiter);
char *my_strndup(const char *string, size_t bytes);
int16_t my_strcmp(char const *s1, char const *s2);
size_t my_strlen(char const *string);
