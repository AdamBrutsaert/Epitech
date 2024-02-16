/*
** EPITECH PROJECT, 2024
** insert_s.c
** File description:
** insert_s.c
*/

#include "string.h"

void insert_s(string_t *self, size_t pos, const string_t *str)
{
    if (str == NULL) {
        insert_c(self, pos, NULL);
    } else {
        insert_c(self, pos, str->str);
    }
}
