/*
** EPITECH PROJECT, 2023
** redirection_get_type.c
** File description:
** redirection_get_type.c
*/

#include "shell/redirection_impl.h"

redirection_type_t redirection_get_type(redirection_t *redirection)
{
    return redirection->type;
}
