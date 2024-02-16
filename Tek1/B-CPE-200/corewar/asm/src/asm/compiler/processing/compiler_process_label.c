/*
** EPITECH PROJECT, 2023
** compiler_process_label.c
** File description:
** compiler_process_label.c
*/

#include "asm/compiler_impl.h"

static size_t get_offset(compiler_t *compiler)
{
    size_t length = VEC_LEN(compiler->operations);
    operation_t *last;

    if (length == 0)
        return 0;
    last = vec_get(compiler->operations, length - 1);
    return last->offset + compiler_get_operation_size(compiler, last);
}

bool compiler_process_label(compiler_t *compiler, lexer_t *lexer)
{
    token_t *token = lexer_next(lexer);
    char *label = string_to_cstr(compiler->scratch,
        string_slice(compiler->scratch, token->value, 0,
            string_get_length(token->value) - 1));

    if (map_get(compiler->labels, label) != NULL) {
        compiler_error(compiler, token, "label already defined");
        return false;
    }
    map_set(compiler->labels, label, get_offset(compiler));
    return true;
}
