/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_delete
*/

#include "shell/alias_impl.h"
#include "my/memory.h"
#include <stdlib.h>

void alias_destroy(alias_t *alias)
{
    if (alias == NULL)
        return;
    free(alias->name);
    my_array_free(alias->values);
    free(alias);
}
