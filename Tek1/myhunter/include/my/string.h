/*
** EPITECH PROJECT, 2022
** string.h
** File description:
** string.h
*/

#pragma once

#include <stdint.h>

uint64_t my_strlen(char const *string);

int8_t my_strcmp(char const *s1, char const *s2);
int8_t my_strncmp(char const *s1, char const *s2, uint64_t n);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, uint64_t n);

char *my_strdup(char const *string);
