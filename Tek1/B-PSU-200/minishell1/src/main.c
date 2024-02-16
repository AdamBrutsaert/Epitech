/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "shell.h"
#include "my/error.h"

static int run(char **env)
{
    shell_t *shell = shell_create(env);
    int status;

    if (ERROR != OK)
        return 84;
    status = shell_run(shell);
    if (ERROR != OK) {
        shell_destroy(shell);
        return 84;
    }
    shell_destroy(shell);
    return status;
}

int main(
    int argc,
    __attribute__((unused)) char **argv,
    char **env
)
{
    if (argc != 1)
        return 84;
    return run(env);
}
