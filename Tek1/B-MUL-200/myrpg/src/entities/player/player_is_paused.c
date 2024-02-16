/*
** EPITECH PROJECT, 2023
** player_is_paused.c
** File description:
** player_is_paused.c
*/

#include "entities/player.h"
#include "layers/level_impl.h"

bool player_is_paused(entity_t *entity)
{
    layer_t *layer = entity_get_layer(entity);
    level_t *level = layer_get_data(layer);

    return level->is_paused;
}
