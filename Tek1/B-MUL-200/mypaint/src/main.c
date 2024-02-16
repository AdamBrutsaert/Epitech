/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "paint/app.h"

int run(void)
{
    app_t *app = app_create();
    bool status;

    if (!app)
        return 84;
    status = app_run(app);
    app_destroy(app);
    return !status * 84;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv,
    char **env)
{
    if (!env[0])
        return 84;
    return run();
}
