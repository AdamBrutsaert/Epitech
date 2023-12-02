/*
** EPITECH PROJECT, 2023
** layer.h
** File description:
** layer.h
*/

#pragma once

#include "engine/layer.h"

struct layer {
    void *data;
    on_attach_t on_attach;
    on_detach_t on_detach;
    on_event_t on_event;
    on_update_t on_update;
    on_render_t on_render;
};

bool layer_on_attach(layer_t *layer, struct context *ctx);
void layer_on_detach(layer_t *layer, struct context *ctx);
bool layer_on_event(layer_t *layer, struct context *ctx, sfEvent *event);
bool layer_on_update(layer_t *layer, struct context *ctx, float dt);
bool layer_on_render(layer_t *layer, struct context *ctx);
