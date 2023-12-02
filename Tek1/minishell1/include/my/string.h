/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>

uint64_t my_strlen(char const *string);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *string);
char *my_strndup(char const *string, uint64_t bytes);
char *my_strcat(char *dest, char const *src);
int16_t my_strncmp(char const *s1, char const *s2, uint64_t bytes);
int16_t my_strcmp(char const *s1, char const *s2);

uint64_t my_strarrlen(char **array);
char **my_strarrdup(char **array);
void my_strarrfree(char **array);
char **my_strarrmove(char **dest, char **src);
