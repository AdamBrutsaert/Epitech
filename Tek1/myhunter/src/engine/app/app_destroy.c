/*
** EPITECH PROJECT, 2022
** app_destroy.c
** File description:
** app_destroy.c
*/

#include "engine.h"
#include "my.h"

void app_destroy(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    my_free(app->signal_queue.signals);
    my_free(app);
}
