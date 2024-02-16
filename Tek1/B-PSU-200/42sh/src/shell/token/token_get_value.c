/*
** EPITECH PROJECT, 2023
** token_get_value.c
** File description:
** token_get_value.c
*/

#include "shell/token_impl.h"

char *token_get_value(token_t *token)
{
    return token->value;
}
