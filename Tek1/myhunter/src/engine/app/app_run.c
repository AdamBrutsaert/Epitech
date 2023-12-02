/*
** EPITECH PROJECT, 2022
** app_run.c
** File description:
** app_run.c
*/

#include "engine.h"
#include "my.h"

static void app_handle_events(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        scene_on_event(app->scene, &event);
    }
}

static void app_handle_signals(app_t *app)
{
    uint32_t length = app->signal_queue.length;

    for (uint32_t i = 0; i < length; i++)
        scene_on_signal(app->scene, app->signal_queue.signals[i].sender,
            app->signal_queue.signals[i].name);
    my_memmove(app->signal_queue.signals, &app->signal_queue.signals[length],
        sizeof(signal_t) * (app->signal_queue.length - length));
    app->signal_queue.length -= length;
}

static void app_try_switch_scene(app_t *app)
{
    if (app->next_scene) {
        if (app->scene) {
            scene_on_detach(app->scene);
            scene_destroy(app->scene);
        }
        app->scene = app->next_scene;
        app->next_scene = NULL;
        scene_on_attach(app->scene);
    }
}

void app_run(app_t *app)
{
    sfClock *clock = sfClock_create();

    if (!app->next_scene)
        return;
    app_try_switch_scene(app);
    while (sfRenderWindow_isOpen(app->window)) {
        app_try_switch_scene(app);
        app_handle_events(app);
        app_handle_signals(app);
        scene_on_update(app->scene,
                sfTime_asSeconds(sfClock_restart(clock)));
        sfRenderWindow_clear(app->window, sfColor_fromRGB(26,26,26));
        scene_on_render(app->scene);
        sfRenderWindow_display(app->window);
    }
    scene_on_detach(app->scene);
    scene_destroy(app->scene);
    sfClock_destroy(clock);
}
