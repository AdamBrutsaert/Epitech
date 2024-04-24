/*
** EPITECH PROJECT, 2024
** token_create.c
** File description:
** token_create.c
*/

#include "parsing/token.h"

#include "my/memory/allocation.h"

token_t *token_create(token_type_t type, const string_t *value)
{
    token_t *token = allocate(sizeof(token_t));

    token->type = type;
    token->value = string_clone(value);
    return token;
}
