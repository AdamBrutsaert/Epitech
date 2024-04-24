/*
** EPITECH PROJECT, 2024
** string_destroy.c
** File description:
** string_destroy.c
*/

#include "my/memory/string.h"

void string_destroy(string_t *self)
{
    vec_destroy(self);
}
