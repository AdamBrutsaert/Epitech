/*
** EPITECH PROJECT, 2023
** builtin_cd.c
** File description:
** builtin_cd.c
*/

#include "shell/builtins.h"
#include "my/string.h"
#include "my/stdio.h"

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

static bool check(interpreter_t *interpreter, char const *path)
{
    struct stat stats;

    if (access(path, F_OK) != 0) {
        my_eputs(path);
        my_eputs(errno == EACCES
            ? ": Permission denied.\n"
            : ": No such file or directory.\n");
        errno = 0;
        interpreter_set_status(interpreter, 1);
        return false;
    }
    stat(path, &stats);
    if (!S_ISDIR(stats.st_mode)) {
        my_eputs(path);
        my_eputs(": Not a directory.\n");
        interpreter_set_status(interpreter, 1);
        return false;
    }
    return true;
}

static void change(interpreter_t *interpreter, char const *path)
{
    char *old;

    if (!check(interpreter, path))
        return;
    old = getcwd(NULL, 0);
    chdir(path);
    interpreter_set_env(interpreter, "OLDPWD", old);
    interpreter_set_env(interpreter, "PWD", path);
    interpreter_set_status(interpreter, 0);
    free(old);
}

static void cd_back(interpreter_t *interpreter)
{
    char *old = interpreter_get_env_value(interpreter, "OLDPWD");

    if (old == NULL) {
        change(interpreter, "");
    } else {
        change(interpreter, old);
        free(old);
    }
}

static void cd_to_home(interpreter_t *interpreter)
{
    char *home = interpreter_get_env_value(interpreter, "HOME");

    if (home == NULL) {
        my_eputs("cd: No home directory.\n");
        interpreter_set_status(interpreter, 1);
    }
    change(interpreter, home);
    free(home);
}

void builtin_cd(interpreter_t *interpreter, char **arguments)
{
    size_t length = 0;

    while (arguments[length] != NULL)
        length++;
    if (length == 1)
        return cd_to_home(interpreter);
    if (length == 2) {
        if (!my_strcmp(arguments[1], "-"))
            return cd_back(interpreter);
        return change(interpreter, arguments[1]);
    }
    my_eputs("cd: Too many arguments.\n");
    interpreter_set_status(interpreter, 1);
}
