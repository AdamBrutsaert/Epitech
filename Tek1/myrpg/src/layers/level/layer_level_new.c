/*
** EPITECH PROJECT, 2023
** layer_level_new.c
** File description:
** layer_level_new.c
*/

#include "layers/level_impl.h"

layer_t *level_new(void)
{
    layer_t *layer = layer_new(sizeof(level_t));

    if (layer == NULL)
        return NULL;
    layer_bind_on_attach(layer, layer_level_on_attach);
    layer_bind_on_detach(layer, layer_level_on_detach);
    layer_bind_on_event(layer, layer_level_on_event);
    layer_bind_on_update(layer, layer_level_on_update);
    layer_bind_on_render(layer, layer_level_on_render);
    return layer;
}
