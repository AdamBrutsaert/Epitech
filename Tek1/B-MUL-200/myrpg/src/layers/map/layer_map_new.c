/*
** EPITECH PROJECT, 2023
** layer_map_new.c
** File description:
** layer_map_new.c
*/

#include "layers/map_impl.h"

layer_t *layer_map_new(const char *map, const char *collisions)
{
    layer_t *layer = layer_new(sizeof(layer_map_t));
    layer_map_t *data;

    if (layer == NULL)
        return NULL;
    data = layer_get_data(layer);
    data->map = map;
    data->collisions = collisions;
    layer_bind_on_attach(layer, layer_map_on_attach);
    layer_bind_on_detach(layer, layer_map_on_detach);
    layer_bind_on_event(layer, layer_map_on_event);
    layer_bind_on_update(layer, layer_map_on_update);
    layer_bind_on_render(layer, layer_map_on_render);
    return layer;
}
