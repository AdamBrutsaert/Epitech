/*
** EPITECH PROJECT, 2022
** app_create.c
** File description:
** app_create.c
*/

#include "engine.h"
#include "my.h"

app_t *app_create(uint32_t width, uint32_t height,
    char const *title)
{
    app_t *app = my_malloc(sizeof(app_t));

    app->window = sfRenderWindow_create((sfVideoMode){width,height,32},
        title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(app->window, 60);
    app->scene = NULL;
    app->next_scene = NULL;
    app->signal_queue.signals = NULL;
    app->signal_queue.length = 0;
    app->signal_queue.capacity = 0;
    return app;
}
