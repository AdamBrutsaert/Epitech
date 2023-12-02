/*
** EPITECH PROJECT, 2023
** layer_map_on_update.c
** File description:
** layer_map_on_update.c
*/

#include "layers/map_impl.h"
#include "layers/level.h"

bool layer_map_on_update(layer_t *layer, float dt)
{
    layer_map_t *map = layer_get_data(layer);
    sfView *camera = level_get_view(map->layer);
    sfView *view = layer_get_view(layer);

    sfView_setCenter(view, sfView_getCenter(camera));
    sfView_setSize(view, sfView_getSize(camera));
    return true;
}
