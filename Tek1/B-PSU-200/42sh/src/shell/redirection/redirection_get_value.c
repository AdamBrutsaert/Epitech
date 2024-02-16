/*
** EPITECH PROJECT, 2023
** redirection_get_value.c
** File description:
** redirection_get_value.c
*/

#include "shell/redirection_impl.h"

char *redirection_get_value(redirection_t *redirection)
{
    return redirection->value;
}
