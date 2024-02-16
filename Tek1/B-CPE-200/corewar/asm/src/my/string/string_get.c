/*
** EPITECH PROJECT, 2023
** string_get.c
** File description:
** string_get.c
*/

#include "my/string_impl.h"

char string_get(string_t *string, size_t index)
{
    if (index >= string->length)
        return '\0';
    return string->value[index];
}
