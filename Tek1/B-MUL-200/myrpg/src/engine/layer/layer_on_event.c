/*
** EPITECH PROJECT, 2023
** layer_on_event.c
** File description:
** layer_on_event.c
*/

#include "engine/layer_impl.h"

bool layer_on_event(layer_t *layer, sfEvent *event)
{
    engine_t *engine = layer_get_engine(layer);

    for (size_t i = 0; i < layer->entities_length; i++) {
        if (!entity_on_event(layer->entities[i], event))
            return false;
        if (engine_should_prevent_propagation(engine))
            break;
    }
    if (layer->on_event && !layer->on_event(layer, event))
        return false;
    return true;
}
