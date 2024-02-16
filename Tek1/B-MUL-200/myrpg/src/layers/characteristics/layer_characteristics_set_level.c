/*
** EPITECH PROJECT, 2023
** layer_characteristics_set_level.c
** File description:
** layer_characteristics_set_level.c
*/

#include "layers/characteristics_impl.h"

void layer_characteristics_set_level(layer_t *layer, layer_t *level)
{
    layer_characteristics_t *data = layer_get_data(layer);

    data->level = level;
}
