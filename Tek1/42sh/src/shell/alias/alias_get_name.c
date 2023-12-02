/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_get_name
*/

#include "shell/alias_impl.h"

char *alias_get_name(alias_t *alias)
{
    return alias->name;
}
