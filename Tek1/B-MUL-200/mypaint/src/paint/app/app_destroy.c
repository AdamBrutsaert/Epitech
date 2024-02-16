/*
** EPITECH PROJECT, 2023
** app_destroy.c
** File description:
** app_destroy.c
*/

#include "private/paint/app.h"
#include "my/memory.h"

void app_destroy(app_t *app)
{
    if (!app)
        return;
    context_destroy(app->ctx);
    layer_destroy(app->painting);
    layer_destroy(app->toolbox);
    layer_destroy(app->menu);
    my_free(app);
}
