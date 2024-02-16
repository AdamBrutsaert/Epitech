/*
** EPITECH PROJECT, 2023
** my_strarrdup.c
** File description:
** my_strarrdup.c
*/

#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>

char **my_strarrdup(char **array)
{
    char **copy = malloc((my_strarrlen(array) + 1) * sizeof(char *));
    uint64_t i = 0;

    if (copy == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    for (; array[i] != NULL; i++) {
        copy[i] = my_strdup(array[i]);
        if (ERROR != OK) {
            my_strarrfree(copy);
            THROW_NULL(ERROR);
        }
    }
    copy[i] = NULL;
    return copy;
}
