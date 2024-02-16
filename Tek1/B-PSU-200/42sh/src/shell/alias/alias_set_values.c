/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_set_values
*/

#include "shell/alias_impl.h"
#include "my/memory.h"
#include <stdlib.h>
#include <string.h>

bool alias_set_values(alias_t *alias, char **values, void *method)
{
    char *dup = NULL;

    if (method == free) {
        my_array_free(alias->values);
        alias->values = calloc(sizeof(char *), my_array_length(values));
    }
    if (method == calloc)
        alias->values = calloc(sizeof(char *), my_array_length(values));
    for (int i = 0; values[i + 2] != NULL; i++) {
        dup = strdup(values[i + 2]);
        if (dup == NULL)
            return false;
        alias->values[i] = dup;
    }
    return true;
}
