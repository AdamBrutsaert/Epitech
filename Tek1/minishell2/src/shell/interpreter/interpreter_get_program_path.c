/*
** EPITECH PROJECT, 2023
** interpreter_get_program_path.c
** File description:
** interpreter_get_program_path.c
*/

#include "shell/interpreter.h"
#include "my/stdio.h"
#include "my/string.h"
#include "my/memory.h"

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

static char *concat_path(const char *directory, const char *name)
{
    char *path = malloc(my_strlen(directory) + my_strlen(name) + 2);

    if (path == NULL)
        return NULL;
    path[0] = '\0';
    my_strcat(path, directory);
    my_strcat(path, "/");
    my_strcat(path, name);
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
        if (!my_strcmp(file->d_name, name)) {
            path = concat_path(directory, name);
            break;
        }
    }
    closedir(dir);
    return path;
}

static char *get_path(interpreter_t *interpreter, const char *name)
{
    char **directories;
    char *path = NULL;

    if (!access(name, F_OK))
        return my_strdup(name);
    directories = interpreter_get_path_directories(interpreter);
    if (directories == NULL)
        return NULL;
    for (size_t i = 0; directories[i] != NULL && path == NULL; i++)
        path = find_in_directory(directories[i], name);
    my_freearr(directories);
    return path;
}

char *interpreter_get_program_path(
    interpreter_t *interpreter,
    const char *name
)
{
    struct stat stats;
    char *path = get_path(interpreter, name);

    if (path == NULL) {
        my_eputs(name);
        my_eputs(": Command not found.\n");
        interpreter_set_status(interpreter, 1);
        return NULL;
    }
    stat(path, &stats);
    if (S_ISDIR(stats.st_mode) || access(path, X_OK) != 0) {
        my_eputs(name);
        my_eputs(": Permission denied.\n");
        free(path);
        interpreter_set_status(interpreter, 1);
        return NULL;
    }
    return path;
}
