/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_delete
*/

#include "shell/alias_impl.h"
#include "my/memory.h"
#include <stdlib.h>

void alias_delete_all(alias_t *alias)
{
    alias_t *next = NULL;

    while (alias != NULL) {
        next = alias->next;
        free(alias->name);
        my_array_free(alias->values);
        free(alias);
        alias = next;
    }
}
