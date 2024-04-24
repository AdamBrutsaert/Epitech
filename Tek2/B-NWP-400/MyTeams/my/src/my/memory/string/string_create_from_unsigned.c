/*
** EPITECH PROJECT, 2024
** string_create_from_unsigned.c
** File description:
** string_create_from_unsigned.c
*/

#include "my/memory/string.h"

static void push_number(string_t *self, uint64_t number)
{
    if (number >= 10)
        push_number(self, number / 10);
    vec_push_back(self, &"0123456789"[number % 10]);
}

string_t *string_create_from_unsigned(uint64_t number)
{
    string_t *self = vec_create(sizeof(char));

    push_number(self, number);
    vec_push_back(self, &(char){0});
    return self;
}
