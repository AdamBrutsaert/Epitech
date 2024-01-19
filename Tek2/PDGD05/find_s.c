/*
** EPITECH PROJECT, 2024
** find_s.c
** File description:
** find_s.c
*/

#include "string.h"

int find_s(const string_t *self, const string_t *str, size_t pos)
{
    if (str == NULL)
        return find_c(self, NULL, pos);
    return find_c(self, str->str, pos);
}
