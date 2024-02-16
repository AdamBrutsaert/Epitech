/*
** EPITECH PROJECT, 2023
** layer_map_set_layer_level.c
** File description:
** layer_map_set_layer_level.c
*/

#include "layers/map_impl.h"
#include "layers/level.h"

void layer_map_set_level_layer(layer_t *layer, layer_t *level)
{
    layer_map_t *map = layer_get_data(layer);

    map->layer = level;
}
