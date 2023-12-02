/*
** EPITECH PROJECT, 2023
** engine_handle_layer_events.c
** File description:
** engine_handle_layer_events.c
*/

#include "engine_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(engine_t *engine)
{
    size_t capacity = engine->layers_capacity * 2 + !engine->layers_capacity;
    layer_t **layers = malloc(sizeof(layer_t *) * capacity);

    if (layers == NULL)
        return false;
    my_memcpy(
        layers,
        engine->layers,
        sizeof(layer_t *) * engine->layers_length
    );
    free(engine->layers);
    engine->layers = layers;
    engine->layers_capacity = capacity;
    return true;
}

static bool push_layer(engine_t *engine, layer_t *layer)
{
    if (engine->layers_length == engine->layers_capacity && !grow(engine))
        return false;
    engine->layers[engine->layers_length] = layer;
    engine->layers_length++;
    layer_set_engine(layer, engine);
    return layer_on_attach(layer);
}

static void pop_layers(engine_t *engine, size_t count)
{
    layer_t *layer;

    while (count && engine->layers_length > 0) {
        layer = engine->layers[engine->layers_length - 1];
        layer_on_detach(layer);
        layer_delete(layer);
        engine->layers_length--;
        count--;
    }
}

static void remove_layer(engine_t *engine, layer_t *layer)
{
    size_t index = 0;

    for (; index < engine->layers_length; index++) {
        if (engine->layers[index] == layer)
            break;
    }
    if (index == engine->layers_length)
        return;
    layer_on_detach(layer);
    layer_delete(layer);
    for (size_t i = index; i < engine->layers_length - 1; i++)
        engine->layers[i] = engine->layers[i + 1];
    engine->layers_length--;
}

bool engine_handle_layer_events(engine_t *engine)
{
    for (size_t i = 0; i < engine->events_length; i++) {
        if (engine->events[i].type == EVENT_PUSH
            && !push_layer(engine, engine->events[i].layer))
            return false;
        if (engine->events[i].type == EVENT_POP)
            pop_layers(engine, 1);
        if (engine->events[i].type == EVENT_CLEAR)
            pop_layers(engine, engine->layers_length);
        if (engine->events[i].type == EVENT_REMOVE)
            remove_layer(engine, engine->events[i].layer);
    }
    engine->events_length = 0;
    return true;
}
