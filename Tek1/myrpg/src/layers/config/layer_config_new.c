/*
** EPITECH PROJECT, 2023
** layer_config_new.c
** File description:
** layer_config_new.c
*/

#include "layers/config_impl.h"

layer_t *layer_config_new(void)
{
    layer_t *layer = layer_new(sizeof(layer_config_t));

    if (layer == NULL)
        return NULL;
    layer_bind_on_attach(layer, layer_config_on_attach);
    layer_bind_on_detach(layer, layer_config_on_detach);
    layer_bind_on_event(layer, layer_config_on_event);
    layer_bind_on_update(layer, layer_config_on_update);
    layer_bind_on_render(layer, layer_config_on_render);
    return layer;
}
