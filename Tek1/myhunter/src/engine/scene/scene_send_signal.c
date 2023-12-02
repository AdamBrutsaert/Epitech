/*
** EPITECH PROJECT, 2022
** scene_send_signal.c
** File description:
** scene_send_signal.c
*/

#include "engine.h"
#include "my.h"

void scene_send_signal(scene_t *scene, char const *name)
{
    app_t *app = scene->app;

    if (app->signal_queue.length == app->signal_queue.capacity) {
        app->signal_queue.capacity *= 2;
        app->signal_queue.capacity += !app->signal_queue.capacity;
        app->signal_queue.signals = my_realloc(app->signal_queue.signals,
            app->signal_queue.capacity * sizeof(signal_t));
    }
    app->signal_queue.signals[app->signal_queue.length].sender = scene;
    app->signal_queue.signals[app->signal_queue.length].name = name;
    app->signal_queue.length++;
}
