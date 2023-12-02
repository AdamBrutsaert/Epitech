/*
** EPITECH PROJECT, 2023
** layer_map_on_attach.c
** File description:
** layer_map_on_attach.c
*/

#include "layers/map_impl.h"

#include "entities/map.h"

bool layer_map_on_attach(layer_t *layer)
{
    layer_map_t *data = layer_get_data(layer);
    entity_t *map = entity_map_new(data->map, data->collisions);

    if (map == NULL)
        return false;
    return layer_add_entity(layer, map);
}
