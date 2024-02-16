/*
** EPITECH PROJECT, 2023
** layer_settings_new.c
** File description:
** layer_settings_new.c
*/

#include "layers/settings_impl.h"

layer_t *layer_settings_new(layer_t *level)
{
    layer_t *layer = layer_new(sizeof(layer_settings_t));
    layer_settings_t *settings;

    if (layer == NULL)
        return NULL;
    settings = layer_get_data(layer);
    settings->level = level;
    layer_bind_on_attach(layer, layer_settings_on_attach);
    layer_bind_on_detach(layer, layer_settings_on_detach);
    layer_bind_on_event(layer, layer_settings_on_event);
    layer_bind_on_update(layer, layer_settings_on_update);
    layer_bind_on_render(layer, layer_settings_on_render);
    return layer;
}
