/*
** EPITECH PROJECT, 2023
** layer_bind_on_render.c
** File description:
** layer_bind_on_render.c
*/

#include "engine/layer_impl.h"

void layer_bind_on_render(layer_t *layer, layer_on_render_t on_render)
{
    layer->on_render = on_render;
}
