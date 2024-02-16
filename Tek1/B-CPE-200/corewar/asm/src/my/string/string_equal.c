/*
** EPITECH PROJECT, 2023
** string_equal.c
** File description:
** string_equal.c
*/

#include "my/string_impl.h"

bool string_equal(string_t *string1, string_t *string2)
{
    if (string1->length != string2->length)
        return false;
    for (size_t i = 0; i < string1->length; i++)
        if (string1->value[i] != string2->value[i])
            return false;
    return true;
}
