/*
** EPITECH PROJECT, 2022
** string.h
** File description:
** string.h
*/

#pragma once

#include <stdint.h>

uint64_t my_strlen(char const *str);
int32_t my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
