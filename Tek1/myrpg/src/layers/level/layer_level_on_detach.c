/*
** EPITECH PROJECT, 2023
** layer_level_on_detach.c
** File description:
** layer_level_on_detach.c
*/

#include "layers/level_impl.h"

void layer_level_on_detach(layer_t *layer)
{
    level_t *level = layer_get_data(layer);

    sfMusic_destroy(level->music);
}
