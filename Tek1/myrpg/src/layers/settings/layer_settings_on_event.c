/*
** EPITECH PROJECT, 2023
** layer_settings_on_event.c
** File description:
** layer_settings_on_event.c
*/

#include "layers/settings_impl.h"
#include "layers/level_impl.h"
#include "entities/button.h"

static void center_buttons(layer_t *layer, layer_settings_t *s)
{
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));

    button_set_position(s->resume, size.x / 2.0f - 203, size.y / 2.0f - 50);
    button_set_position(s->save, size.x / 2.0f - 203, size.y / 2.0f);
    button_set_position(s->load, size.x / 2.0f - 203, size.y / 2.0f + 50.0f);
    button_set_position(s->config, size.x / 2.0f - 203, size.y / 2.0f + 100.0f);
    button_set_position(s->quit, size.x / 2.0f - 203, size.y / 2.0f + 150.0f);
}

bool layer_settings_on_event(layer_t *layer, sfEvent *event)
{
    sfView *view = layer_get_view(layer);
    layer_settings_t *settings = layer_get_data(layer);
    level_t *level;

    if (event->type == sfEvtResized) {
        sfView_setSize(view, (sfVector2f){event->size.width,
            event->size.height});
        sfView_setCenter(view, (sfVector2f){event->size.width / 2.0f,
            event->size.height / 2.0f});
        center_buttons(layer, settings);
    } else {
        engine_prevent_propagation(layer_get_engine(layer));
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        level = layer_get_data(settings->level);
        level->is_paused = false;
        engine_pop_layer(layer_get_engine(layer));
    }
    return true;
}
