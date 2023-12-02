/*
** EPITECH PROJECT, 2023
** layer_bind_on_update.c
** File description:
** layer_bind_on_update.c
*/

#include "engine/layer_impl.h"

void layer_bind_on_update(layer_t *layer, layer_on_update_t on_update)
{
    layer->on_update = on_update;
}
