/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_new.c
** File description:
** layer_ingame_inventory_new.c
*/

#include "layers/ingame_inventory_impl.h"

layer_t *layer_ingame_inventory_new(layer_t *level_layer)
{
    layer_t *layer = layer_new(sizeof(layer_ingame_inventory_t));
    layer_ingame_inventory_t *self = layer_get_data(layer);

    if (layer == NULL)
        return NULL;
    self->level = level_layer;
    layer_bind_on_attach(layer, layer_ingame_inventory_on_attach);
    layer_bind_on_detach(layer, layer_ingame_inventory_on_detach);
    layer_bind_on_event(layer, layer_ingame_inventory_on_event);
    layer_bind_on_update(layer, layer_ingame_inventory_on_update);
    layer_bind_on_render(layer, layer_ingame_inventory_on_render);
    return layer;
}
