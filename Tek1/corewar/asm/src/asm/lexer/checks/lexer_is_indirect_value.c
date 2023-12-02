/*
** EPITECH PROJECT, 2023
** lexer_is_indirect_value.c
** File description:
** lexer_is_indirect_value.c
*/

#include "asm/lexer_impl.h"

bool lexer_is_indirect_value(string_t *s)
{
    if ((string_get_length(s) == 1 && string_get(s, 0) == '-')
        || string_get_length(s) == 0)
        return false;
    for (size_t i = string_get(s, 0) == '-'; i < string_get_length(s); i++) {
        if (!my_strcontains("0123456789", string_get(s, i)))
            return false;
    }
    return true;
}
