/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_find
*/

#include "shell/alias_impl.h"

#include <string.h>

char **alias_find_values(alias_t *alias, char *name)
{
    for (; alias != NULL; alias = alias_get_next(alias))
        if (!strcmp(alias_get_name(alias), name))
            return alias_get_values(alias);
    return NULL;
}
