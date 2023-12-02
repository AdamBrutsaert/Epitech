/*
** EPITECH PROJECT, 2023
** layer_is_colliding.c
** File description:
** layer_is_colliding.c
*/

#include "engine/layer_impl.h"

entity_t *layer_is_colliding(layer_t *layer, entity_t *entity)
{
    for (size_t i = 0; i < layer->entities_length; i++) {
        if (layer->entities[i] == entity)
            continue;
        if (entity_is_colliding(layer->entities[i], entity))
            return layer->entities[i];
    }
    return NULL;
}
