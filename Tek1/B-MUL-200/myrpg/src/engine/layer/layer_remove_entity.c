/*
** EPITECH PROJECT, 2023
** layer_remove_entity.c
** File description:
** layer_remove_entity.c
*/

#include "engine/layer_impl.h"

void layer_remove_entity(layer_t *layer, entity_t *entity)
{
    size_t index = 0;

    for (; index < layer->entities_length; index++) {
        if (layer->entities[index] == entity)
            break;
    }
    if (index == layer->entities_length)
        return;
    for (; index < layer->entities_length - 1; index++)
        layer->entities[index] = layer->entities[index + 1];
    layer->entities_length--;
    entity_on_detach(entity);
    entity_delete(entity);
}
