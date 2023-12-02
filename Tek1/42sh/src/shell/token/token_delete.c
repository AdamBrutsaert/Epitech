/*
** EPITECH PROJECT, 2023
** token_delete.c
** File description:
** token_delete.c
*/

#include "shell/token_impl.h"

#include <stdlib.h>

void token_delete(token_t *token)
{
    if (token == NULL)
        return;
    free(token->value);
    free(token);
}
