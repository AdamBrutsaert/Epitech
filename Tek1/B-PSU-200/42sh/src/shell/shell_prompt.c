/*
** EPITECH PROJECT, 2023
** shell_prompt.c
** File description:
** shell_prompt.c
*/

#include "shell_impl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

static void print_status(shell_t *shell)
{
    if (shell->status == 0)
        printf("\033[0;32m");
    else
        printf("\033[0;31m");
    printf("➜  ");
    printf("\033[0m");
}

static void print_user(void)
{
    __uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    char hostname[31];

    hostname[30] = '\0';
    gethostname(hostname, 30);
    if (pw != NULL) {
        printf("[%s@%s] ", pw->pw_name, hostname);
    }
}

static int print_path(void)
{
    char *cwd = getcwd(NULL, 0);
    char *tok;
    char *path = NULL;

    if (cwd == NULL)
        return 84;
    tok = strtok(cwd, "/");
    while (tok != NULL) {
        free(path);
        path = strdup(tok);
        tok = strtok(NULL, "/");
    }
    if (path != NULL)
        printf("%s ", path);
    free(path);
    free(cwd);
    return 0;
}

void shell_prompt(shell_t *shell)
{
    printf("\x1B[35m");
    print_user();
    printf("\033[0;36m");
    print_path();
    printf("\033[0m");
    print_status(shell);
    fflush(stdout);
}
