/*
** EPITECH PROJECT, 2023
** compiler_get_output_path.c
** File description:
** compiler_get_output_path.c
*/

#include "asm/compiler_impl.h"

char *compiler_get_output_path(arena_t *arena, const char *input)
{
    string_t *string = string_from(arena, input);
    size_t dot_pos = string_get_length(string);

    for (; dot_pos > 0; dot_pos--) {
        if (string_get(string, dot_pos - 1) == '.')
            break;
    }
    if (dot_pos > 1)
        string = string_slice(arena, string, 0, dot_pos - 1);
    string = string_append(arena, string, ".cor");
    return string_to_cstr(arena, string);
}
