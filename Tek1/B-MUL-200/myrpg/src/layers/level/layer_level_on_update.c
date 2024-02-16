/*
** EPITECH PROJECT, 2023
** layer_level_on_update.c
** File description:
** layer_level_on_update.c
*/

#include "layers/level_impl.h"

bool layer_level_on_update(layer_t *layer, float dt)
{
    level_t *level = layer_get_data(layer);
    sfView *camera = player_get_view(level->player);
    sfView *view = layer_get_view(layer);

    sfView_setCenter(view, sfView_getCenter(camera));
    sfView_setSize(view, sfView_getSize(camera));
    return true;
}
