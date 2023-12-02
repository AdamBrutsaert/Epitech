/*
** EPITECH PROJECT, 2023
** string.h
** File description:
** string.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

uint64_t my_strlen(char const *string);
int16_t my_strcmp(char const *s1, char const *s2);
int16_t my_strncmp(char const *s1, char const *s2, uint64_t bytes);
uint64_t my_strarrlen(char **array);
