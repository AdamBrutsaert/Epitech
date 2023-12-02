/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_get_values
*/

#include "shell/alias_impl.h"

char **alias_get_values(alias_t *alias)
{
    return alias->values;
}
