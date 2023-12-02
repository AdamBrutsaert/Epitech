/*
** EPITECH PROJECT, 2023
** shell_find_binary.c
** File description:
** shell_find_binary.c
*/

#include "shell.h"
#include "my/error.h"
#include "my/string.h"

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

static char *concat_path(char const *directory, char const *name)
{
    char *path = malloc(my_strlen(directory) + my_strlen(name) + 2);

    if (path == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    path[0] = '\0';
    my_strcat(path, directory);
    my_strcat(path, "/");
    my_strcat(path, name);
    return path;
}

static char *find_in_directory(char const *directory, char const *name)
{
    DIR *dir = opendir(directory);
    struct dirent* file;
    char *path = NULL;

    if (dir == NULL)
        return NULL;
    for (file = readdir(dir); file != NULL; file = readdir(dir)) {
        if (!my_strcmp(file->d_name, name)) {
            path = concat_path(directory, name);
            break;
        }
    }
    closedir(dir);
    return path;
}

char *shell_find_binary(shell_t *shell, char const *name)
{
    char **directories;
    char *path = NULL;

    if (!access(name, F_OK))
        return my_strdup(name);
    directories = shell_get_path_directories(shell);
    if (ERROR != OK)
        THROW_NULL(ERROR);
    if (directories == NULL)
        return NULL;
    for (uint64_t i = 0; directories[i] && path == NULL; i++) {
        path = find_in_directory(directories[i], name);
        if (ERROR != OK) {
            my_strarrfree(directories);
            THROW_NULL(ERROR);
        }
    }
    my_strarrfree(directories);
    return path;
}
