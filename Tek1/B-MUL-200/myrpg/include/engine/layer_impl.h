/*
** EPITECH PROJECT, 2023
** layer_impl.h
** File description:
** layer_impl.h
*/

#pragma once

#include "layer.h"
#include "engine.h"

typedef struct layer {
    void *data;
    engine_t *engine;
    sfView *view;

    layer_on_attach_t on_attach;
    layer_on_detach_t on_detach;
    layer_on_event_t on_event;
    layer_on_update_t on_update;
    layer_on_render_t on_render;

    entity_t **entities;
    size_t entities_length;
    size_t entities_capacity;
} layer_t;
