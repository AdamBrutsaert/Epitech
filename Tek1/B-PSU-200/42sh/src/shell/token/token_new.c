/*
** EPITECH PROJECT, 2023
** token_new.c
** File description:
** token_new.c
*/

#include "shell/token_impl.h"

#include <stdlib.h>

token_t *token_new(token_type_t type, char *value)
{
    token_t *token = malloc(sizeof(token_t));

    if (token == NULL)
        return NULL;
    token->type = type;
    token->value = value;
    return token;
}
