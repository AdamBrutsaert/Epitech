/*
** EPITECH PROJECT, 2023
** layer_level_on_event.c
** File description:
** layer_level_on_event.c
*/

#include "layers/level_impl.h"
#include "layers/settings.h"

bool layer_level_on_event(layer_t *layer, sfEvent *event)
{
    level_t *level = layer_get_data(layer);
    layer_t *settings;

    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape
        && !level->is_paused) {
        settings = layer_settings_new(layer);
        if (!settings)
            return false;
        if (!engine_push_layer(layer_get_engine(layer), settings))
            return false;
        level->is_paused = true;
    }
    return true;
}
