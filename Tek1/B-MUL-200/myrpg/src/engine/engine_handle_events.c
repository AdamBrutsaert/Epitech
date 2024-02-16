/*
** EPITECH PROJECT, 2023
** engine_handle_events.c
** File description:
** engine_handle_events.c
*/

#include "engine_impl.h"

static bool send_event_to_layers(engine_t *engine, sfEvent *event)
{
    for (size_t i = engine->layers_length; i != 0; i--) {
        if (!layer_on_event(engine->layers[i - 1], event))
            return false;
        if (engine->prevent_propagation) {
            engine->prevent_propagation = false;
            break;
        }
    }
    return true;
}

bool engine_handle_events(engine_t *engine)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(engine->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(engine->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF1)
            engine->show_hitboxes = !engine->show_hitboxes;
        if (!send_event_to_layers(engine, &event))
            return false;
    }
    return true;
}
