/*
** EPITECH PROJECT, 2023
** app_run.c
** File description:
** app_run.c
*/

#include "private/paint/app.h"

bool app_run(app_t *app)
{
    return context_run(app->ctx);
}
