/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

size_t my_strlen(const char *string);

int16_t my_strcmp(char const *s1, char const *s2);
int16_t my_strncmp(char const *s1, char const *s2, size_t bytes);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t bytes);

char *my_strcat(char *dest, char const *src);

char *my_strdup(char const *string);
char *my_strndup(char const *string, size_t bytes);
