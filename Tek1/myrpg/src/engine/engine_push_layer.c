/*
** EPITECH PROJECT, 2023
** engine_push_layer.c
** File description:
** engine_push_layer.c
*/

#include "engine_impl.h"

bool engine_push_layer(engine_t *engine, layer_t *layer)
{
    event_t event = { .type = EVENT_PUSH, .layer = layer };

    return engine_push_event(engine, &event);
}
