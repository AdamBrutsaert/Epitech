/*
** EPITECH PROJECT, 2022
** string.h
** File description:
** string.h
*/

#pragma once

#include "types.h"

u64_t my_strlen(char const *string);

status_t my_strcmp(char const *s1, char const *s2);
status_t my_strncmp(char const *s1, char const *s2, u64_t n);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, u64_t n);

char *my_strdup(char *string);
