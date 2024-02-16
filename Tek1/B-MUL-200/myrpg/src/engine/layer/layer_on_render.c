/*
** EPITECH PROJECT, 2023
** layer_on_render.c
** File description:
** layer_on_render.c
*/

#include "engine/layer_impl.h"

void layer_on_render(layer_t *layer)
{
    sfRenderWindow *window = layer_get_window(layer);

    sfRenderWindow_setView(window, layer->view);
    if (layer->on_render != NULL)
        layer->on_render(layer);
    for (size_t i = 0; i < layer->entities_length; i++)
        entity_on_render(layer->entities[i]);
}
