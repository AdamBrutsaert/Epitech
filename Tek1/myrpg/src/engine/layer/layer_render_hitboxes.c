/*
** EPITECH PROJECT, 2023
** layer_render_hitboxes.c
** File description:
** layer_render_hitboxes.c
*/

#include "engine/layer_impl.h"

void layer_render_hitboxes(layer_t *layer)
{
    sfRenderWindow_setView(layer_get_window(layer), layer->view);
    for (size_t i = 0; i < layer->entities_length; i++)
        entity_render_hitboxes(layer->entities[i]);
}
