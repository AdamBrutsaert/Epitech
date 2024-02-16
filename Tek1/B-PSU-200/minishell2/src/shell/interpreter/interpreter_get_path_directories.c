/*
** EPITECH PROJECT, 2023
** interpreter_get_path_directories.c
** File description:
** interpreter_get_path_directories.c
*/

#include "shell/interpreter.h"
#include "my/string.h"
#include "my/memory.h"

#include <stdlib.h>

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
    return my_strndup(begin, *var - begin);
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
            my_freearr(directories);
            return NULL;
        }
    }
    return directories;
}

char **interpreter_get_path_directories(interpreter_t *interpreter)
{
    char *path = interpreter_get_env_value(interpreter, "PATH");
    char **directories;

    if (path == NULL)
        return NULL;
    directories = get_directories(path);
    free(path);
    return directories;
}
