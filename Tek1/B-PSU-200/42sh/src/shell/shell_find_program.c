/*
** EPITECH PROJECT, 2023
** shell_find_program.c
** File description:
** shell_find_program.c
*/

#include "shell_impl.h"
#include "my/memory.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

static char *concat_path(const char *directory, const char *name)
{
    char *path = malloc(strlen(directory) + strlen(name) + 2);

    if (path == NULL)
        return NULL;
    path[0] = '\0';
    strcat(path, directory);
    strcat(path, "/");
    strcat(path, name);
    return path;
}

static char *find_in_directory(const char *directory, const char *name)
{
    DIR *dir = opendir(directory);
    struct dirent *file;
    char *path = NULL;

    if (dir == NULL)
        return NULL;
    for (file = readdir(dir); file != NULL; file = readdir(dir)) {
        if (!strcmp(file->d_name, name)) {
            path = concat_path(directory, name);
            break;
        }
    }
    closedir(dir);
    return path;
}

static char *get_path(shell_t *shell, const char *name)
{
    char **directories;
    char *path = NULL;

    if (!access(name, F_OK))
        return strdup(name);
    directories = shell_get_path_directories(shell);
    if (directories == NULL)
        return NULL;
    for (size_t i = 0; directories[i] != NULL && path == NULL; i++)
        path = find_in_directory(directories[i], name);
    my_array_free(directories);
    return path;
}

char *shell_find_program(shell_t *shell, const char *program)
{
    struct stat stats;
    char *path = get_path(shell, program);

    if (path == NULL) {
        fprintf(stderr, "%s: Command not found.\n", program);
        shell_set_status(shell, 1);
        return NULL;
    }
    stat(path, &stats);
    if (S_ISDIR(stats.st_mode) || access(path, X_OK) != 0) {
        fprintf(stderr, "%s: Permission denied.\n", program);
        free(path);
        shell_set_status(shell, 1);
        return NULL;
    }
    return path;
}
