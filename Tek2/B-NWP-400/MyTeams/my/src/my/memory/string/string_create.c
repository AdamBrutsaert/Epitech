/*
** EPITECH PROJECT, 2024
** string_create.c
** File description:
** string_create.c
*/

#include "my/memory/string.h"

string_t *string_create(void)
{
    string_t *self = vec_create(sizeof(char));

    vec_push_back(self, &(char){0});
    return self;
}
