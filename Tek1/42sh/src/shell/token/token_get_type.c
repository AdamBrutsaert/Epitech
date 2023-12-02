/*
** EPITECH PROJECT, 2023
** token_get_type.c
** File description:
** token_get_type.c
*/

#include "shell/token_impl.h"

token_type_t token_get_type(token_t *token)
{
    return token->type;
}
