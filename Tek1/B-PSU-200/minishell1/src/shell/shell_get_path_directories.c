/*
** EPITECH PROJECT, 2023
** shell_get_path_directories.c
** File description:
** shell_get_path_directories.c
*/

#include "shell.h"
#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>

static uint64_t get_directories_count(char const *var)
{
    uint64_t count = 0;
    bool new = true;

    for (; *var; var++) {
        if (new) {
            count++;
            new = false;
        }
        new = *var == ':';
    }
    return count;
}

static char *get_next_directory(char const **var)
{
    char const *begin;

    if (**var == ':')
        (*var)++;
    begin = *var;
    while (**var && **var != ':')
        (*var)++;
    return my_strndup(begin, *var - begin);
}

static char **get_directories(char const *var)
{
    uint64_t count = get_directories_count(var);
    char **directories = malloc((count + 1) * sizeof(char *));

    if (directories == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    for (uint64_t i = 0; i < count; i++) {
        directories[i] = get_next_directory(&var);
        if (ERROR != OK) {
            my_strarrfree(directories);
            THROW_NULL(ERROR);
        }
    }
    directories[count] = 0;
    return directories;
}

char **shell_get_path_directories(shell_t *shell)
{
    char *var = shell_get(shell, "PATH");
    char **directories;

    if (ERROR != OK)
        THROW_NULL(ERROR);
    if (var == NULL)
        return NULL;
    directories = get_directories(var);
    free(var);
    return directories;
}
