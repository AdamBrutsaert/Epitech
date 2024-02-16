/*
** EPITECH PROJECT, 2023
** split.h
** File description:
** split.h
*/

#pragma once

#include <stdint.h>

char **split(char const *string);
void split_free(char **array);
uint64_t split_length(char **array);
