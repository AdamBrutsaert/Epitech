/*
** EPITECH PROJECT, 2023
** context.h
** File description:
** context.h
*/

#pragma once

#include "engine/context.h"

struct context {
    sfRenderWindow *window;
    sfView *view;

    layer_t **layers;
    size_t layers_length;
    size_t layers_capacity;
    size_t layers_to_pop;

    bool prevent_propagation;
};

bool context_handle_events(context_t *ctx);
bool context_update(context_t *ctx, float delta);
bool context_render(context_t *ctx);
