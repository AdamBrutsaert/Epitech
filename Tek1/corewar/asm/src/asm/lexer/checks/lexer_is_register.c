/*
** EPITECH PROJECT, 2023
** lexer_is_register.c
** File description:
** lexer_is_register.c
*/

#include "asm/lexer_impl.h"

bool lexer_is_register(string_t *string)
{
    if (string_get_length(string) < 2)
        return false;
    if (string_get(string, 0) != 'r')
        return false;
    for (size_t i = 1; i < string_get_length(string); i++) {
        if (!my_strcontains("0123456789", string_get(string, i)))
            return false;
    }
    return true;
}
