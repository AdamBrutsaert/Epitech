/*
** EPITECH PROJECT, 2023
** builtin_cd.c
** File description:
** builtin_cd.c
*/

#include "builtins.h"
#include "my/string.h"
#include "my/stdio.h"
#include "my/error.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

static bool check(shell_t *shell, char const *path)
{
    struct stat stats;

    if (access(path, F_OK) != 0) {
        my_eputs(path);
        my_eputs(errno == EACCES
            ? ": Permission denied.\n"
            : ": No such file or directory.\n");
        errno = 0;
        shell->status = 1;
        return false;
    }
    stat(path, &stats);
    if (!S_ISDIR(stats.st_mode)) {
        my_eputs(path);
        my_eputs(": Not a directory.\n");
        shell->status = 1;
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
    shell_set(shell, "OLDPWD", old);
    shell_set(shell, "PWD", path);
    shell->status = 0;
    free(old);
}

static void cd_back(shell_t *shell)
{
    char *old = shell_get(shell, "OLDPWD");

    if (ERROR != OK)
        THROW_VOID(ERROR);
    if (old == NULL) {
        change(shell, "");
    } else {
        change(shell, old);
        free(old);
    }
}

static void cd_to_home(shell_t *shell)
{
    char *home = shell_get(shell, "HOME");

    if (ERROR != OK)
        THROW_VOID(ERROR);
    if (home == NULL) {
        my_eputs("cd: No home directory.\n");
        shell->status = 1;
    }
    change(shell, home);
    free(home);
}

void builtin_cd(shell_t *shell, char **arguments)
{
    uint64_t length = my_strarrlen(arguments);

    if (length == 1)
        return cd_to_home(shell);
    if (length == 2) {
        if (!my_strcmp(arguments[1], "-"))
            return cd_back(shell);
        return change(shell, arguments[1]);
    }
    my_eputs("cd: Too many arguments.\n");
    shell->status = 1;
}
