/*
** EPITECH PROJECT, 2023
** engine_remove_layer.c
** File description:
** engine_remove_layer.c
*/

#include "engine_impl.h"

bool engine_remove_layer(engine_t *engine, layer_t *layer)
{
    event_t event = { .type = EVENT_REMOVE, .layer = layer };

    return engine_push_event(engine, &event);
}
