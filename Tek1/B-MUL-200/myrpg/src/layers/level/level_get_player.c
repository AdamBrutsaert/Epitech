/*
** EPITECH PROJECT, 2023
** level_get_player.c
** File description:
** level_get_player.c
*/

#include <stdio.h>

#include "layers/level_impl.h"

entity_t *level_get_player(layer_t *layer)
{
    level_t *level = layer_get_data(layer);

    return level->player;
}
