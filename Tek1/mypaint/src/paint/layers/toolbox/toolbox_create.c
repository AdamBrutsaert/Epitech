/*
** EPITECH PROJECT, 2023
** toolbox_create.c
** File description:
** toolbox_create.c
*/

#include "private/paint/layers/toolbox.h"

layer_t *toolbox_create(void)
{
    layer_t *layer = layer_create(sizeof(toolbox_t));

    if (!layer)
        return NULL;
    layer_bind_on_attach(layer, toolbox_on_attach);
    layer_bind_on_detach(layer, toolbox_on_detach);
    layer_bind_on_event(layer, toolbox_on_event);
    layer_bind_on_update(layer, toolbox_on_update);
    layer_bind_on_render(layer, toolbox_on_render);
    return layer;
}
