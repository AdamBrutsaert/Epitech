/*
** EPITECH PROJECT, 2023
** layer_characteristics_new.c
** File description:
** layer_characteristics_new.c
*/

#include "layers/characteristics_impl.h"

layer_t *layer_characteristics_new(void)
{
    layer_t *layer = layer_new(sizeof(layer_characteristics_t));

    if (layer == NULL)
        return NULL;
    layer_bind_on_attach(layer, layer_characteristics_on_attach);
    layer_bind_on_detach(layer, layer_characteristics_on_detach);
    layer_bind_on_event(layer, layer_characteristics_on_event);
    layer_bind_on_update(layer, layer_characteristics_on_update);
    layer_bind_on_render(layer, layer_characteristics_on_render);
    return layer;
}
