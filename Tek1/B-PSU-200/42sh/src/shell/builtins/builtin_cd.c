/*
** EPITECH PROJECT, 2023
** builtin_cd.c
** File description:
** builtin_cd.c
*/

#include "shell/builtins.h"
#include "my/memory.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

static bool check(shell_t *shell, char const *path)
{
    struct stat stats;

    if (access(path, F_OK) != 0) {
        fprintf(stderr, "%s: %s.\n", path, errno == EACCES
            ? "Permission denied"
            : "No such file or directory");
        errno = 0;
        shell_set_status(shell, 1);
        return false;
    }
    stat(path, &stats);
    if (!S_ISDIR(stats.st_mode)) {
        fprintf(stderr, "%s: Not a directory.\n", path);
        shell_set_status(shell, 1);
        return false;
    }
    return true;
}

static void change(shell_t *shell, char const *path)
{
    char *old;

    if (!check(shell, path))
        return;
    old = getcwd(NULL, 0);
    chdir(path);
    shell_set_env_var(shell, "OLDPWD", old);
    shell_set_env_var(shell, "PWD", path);
    shell_set_status(shell, 0);
    free(old);
}

static void cd_back(shell_t *shell)
{
    char *old = shell_get_env_var(shell, "OLDPWD");

    if (old == NULL) {
        change(shell, "");
    } else {
        change(shell, old);
        free(old);
    }
}

static void cd_to_home(shell_t *shell)
{
    char *home = shell_get_env_var(shell, "HOME");

    if (home == NULL) {
        fprintf(stderr, "cd: No home directory.\n");
        shell_set_status(shell, 1);
    }
    change(shell, home);
    free(home);
}

void builtin_cd(shell_t *shell, char **arguments)
{
    size_t length = my_array_length(arguments);

    if (length == 1)
        return cd_to_home(shell);
    if (length == 2) {
        if (!strcmp(arguments[1], "-"))
            return cd_back(shell);
        return change(shell, arguments[1]);
    }
    fprintf(stderr, "cd: Too many arguments.\n");
    shell_set_status(shell, 1);
}
