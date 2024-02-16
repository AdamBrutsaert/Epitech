/*
** EPITECH PROJECT, 2023
** layer_bind.c
** File description:
** layer_bind.c
*/

#include "private/engine/layer.h"

void layer_bind_on_attach(layer_t *layer, on_attach_t handler)
{
    layer->on_attach = handler;
}

void layer_bind_on_detach(layer_t *layer, on_detach_t handler)
{
    layer->on_detach = handler;
}

void layer_bind_on_event(layer_t *layer, on_event_t handler)
{
    layer->on_event = handler;
}

void layer_bind_on_update(layer_t *layer, on_update_t handler)
{
    layer->on_update = handler;
}

void layer_bind_on_render(layer_t *layer, on_render_t handler)
{
    layer->on_render = handler;
}
