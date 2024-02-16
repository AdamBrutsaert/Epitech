/*
** EPITECH PROJECT, 2024
** empty.c
** File description:
** empty.c
*/

#include "string.h"

int empty(const string_t *self)
{
    return self->str == NULL || self->str[0] == '\0';
}
