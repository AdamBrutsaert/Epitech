/*
** EPITECH PROJECT, 2023
** layer_on_update.c
** File description:
** layer_on_update.c
*/

#include "engine/layer_impl.h"

bool layer_on_update(layer_t *layer, float dt)
{
    if (layer->on_update != NULL && !layer->on_update(layer, dt))
        return false;
    for (size_t i = 0; i < layer->entities_length; i++) {
        if (!entity_on_update(layer->entities[i], dt))
            return false;
    }
    return true;
}
