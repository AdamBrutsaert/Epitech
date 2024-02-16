/*
** EPITECH PROJECT, 2023
** layer_add_entity.c
** File description:
** layer_add_entity.c
*/

#include "engine/layer_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(layer_t *layer)
{
    size_t capacity = layer->entities_capacity * 2 + !layer->entities_capacity;
    entity_t **entities = malloc(sizeof(entity_t *) * capacity);

    if (entities == NULL)
        return false;
    my_memcpy(
        entities,
        layer->entities,
        sizeof(entity_t *) * layer->entities_length
    );
    free(layer->entities);
    layer->entities = entities;
    layer->entities_capacity = capacity;
    return true;
}

bool layer_add_entity(layer_t *layer, entity_t *entity)
{
    if (layer->entities_length == layer->entities_capacity && !grow(layer))
        return false;
    entity_set_layer(entity, layer);
    layer->entities[layer->entities_length] = entity;
    layer->entities_length++;
    return entity_on_attach(entity);
}
