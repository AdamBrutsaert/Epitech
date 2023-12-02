/*
** EPITECH PROJECT, 2023
** layer_get_view.c
** File description:
** layer_get_view.c
*/

#include "layers/level_impl.h"

sfView *level_get_view(layer_t *layer)
{
    level_t *level = layer_get_data(layer);

    return player_get_view(level->player);
}
