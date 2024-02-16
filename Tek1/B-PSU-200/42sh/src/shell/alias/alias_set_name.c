/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell_set_alias_name
*/

#include "shell/alias_impl.h"
#include <stdlib.h>
#include <string.h>

bool alias_set_name(alias_t *alias, char *name)
{
    char *dup = strdup(name);

    if (dup == NULL)
        return false;
    alias->name = dup;
    return true;
}
