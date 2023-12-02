/*
** EPITECH PROJECT, 2023
** layer_on.c
** File description:
** layer_on.c
*/

#include "private/engine/layer.h"

bool layer_on_attach(layer_t *layer, struct context *ctx)
{
    if (layer->on_attach)
        return layer->on_attach(ctx, layer->data);
    return true;
}

void layer_on_detach(layer_t *layer, struct context *ctx)
{
    if (layer->on_detach)
        layer->on_detach(ctx, layer->data);
}

bool layer_on_event(layer_t *layer, struct context *ctx, sfEvent *event)
{
    if (layer->on_event)
        return layer->on_event(ctx, layer->data, event);
    return true;
}

bool layer_on_update(layer_t *layer, struct context *ctx, float dt)
{
    if (layer->on_update)
        return layer->on_update(ctx, layer->data, dt);
    return true;
}

bool layer_on_render(layer_t *layer, struct context *ctx)
{
    if (layer->on_render)
        return layer->on_render(ctx, layer->data);
    return true;
}
