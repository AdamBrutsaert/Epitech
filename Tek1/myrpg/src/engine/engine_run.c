/*
** EPITECH PROJECT, 2023
** engine_run.c
** File description:
** engine_run.c
*/

#include "engine_impl.h"

static bool process_frame(engine_t *engine, float dt)
{
    if (!engine_handle_layer_events(engine))
        return false;
    if (!engine_handle_events(engine))
        return false;
    if (!engine_on_update(engine, dt))
        return false;
    engine_on_render(engine);
    return true;
}

bool engine_run(engine_t *engine)
{
    sfClock *clock = sfClock_create();
    float dt;

    if (clock == NULL)
        return false;
    while (sfRenderWindow_isOpen(engine->window)) {
        dt = sfTime_asSeconds(sfClock_restart(clock));
        if (!process_frame(engine, dt)) {
            sfClock_destroy(clock);
            return false;
        }
    }
    sfClock_destroy(clock);
    return true;
}
