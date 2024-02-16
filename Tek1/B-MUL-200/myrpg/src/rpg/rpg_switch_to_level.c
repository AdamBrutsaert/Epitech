/*
** EPITECH PROJECT, 2023
** rpg_switch_to_level.c
** File description:
** rpg_switch_to_level.c
*/

#include "rpg_impl.h"

#include "layers/level.h"
#include "layers/map.h"
#include "layers/ingame_inventory.h"
#include "layers/characteristics.h"

static layer_t *push_layer(engine_t *engine, layer_t *layer)
{
    if (layer == NULL)
        return NULL;
    if (!engine_push_layer(engine, layer)) {
        layer_delete(layer);
        return NULL;
    }
    return layer;
}

static bool push_layers(engine_t *engine)
{
    layer_t *back = push_layer(engine, layer_map_new(MAP_BACK_IMG, MAP_COL));
    layer_t *level = push_layer(engine, level_new());
    layer_t *front = push_layer(engine, layer_map_new(MAP_FRONT_IMG, NULL));
    layer_t *inventory = push_layer(engine, layer_ingame_inventory_new(level));
    layer_t *characteristics = push_layer(engine, layer_characteristics_new());

    if (!back || !level || !front || !inventory || !characteristics)
        return false;
    layer_map_set_level_layer(back, level);
    layer_map_set_level_layer(front, level);
    layer_characteristics_set_level(characteristics, level);
    return true;
}

bool rpg_switch_to_level(engine_t *engine)
{
    engine_clear_layers(engine);
    return push_layers(engine);
}
