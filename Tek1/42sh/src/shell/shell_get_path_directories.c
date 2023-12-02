/*
** EPITECH PROJECT, 2023
** shell_get_path_directories.c
** File description:
** shell_get_path_directories.c
*/

#include "shell_impl.h"
#include "my/memory.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static size_t get_directories_count(const char *var)
{
    size_t count = 0;
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

static char *get_next_directory(const char **var)
{
    const char *begin;

    if (**var == ':')
        (*var)++;
    begin = *var;
    while (**var && **var != ':')
        (*var)++;
    return strndup(begin, *var - begin);
}

static char **get_directories(const char *var)
{
    size_t count = get_directories_count(var);
    char **directories = malloc((count + 1) * sizeof(char *));

    if (directories == NULL)
        return NULL;
    directories[count] = NULL;
    for (size_t i = 0; i < count; i++) {
        directories[i] = get_next_directory(&var);
        if (directories[i] == NULL) {
            my_array_free(directories);
            return NULL;
        }
    }
    return directories;
}

static char *get_path(shell_t *shell)
{
    char *path = shell_get_env_var(shell, "PATH");

    if (path == NULL)
        path = strdup("/bin:/usr/bin");
    return path;
}

char **shell_get_path_directories(shell_t *shell)
{
    char *path = get_path(shell);
    char **directories;

    if (path == NULL)
        return NULL;
    directories = get_directories(path);
    free(path);
    return directories;
}
