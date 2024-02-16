/*
** EPITECH PROJECT, 2023
** painting_create.c
** File description:
** painting_create.c
*/

#include "private/paint/layers/painting.h"

layer_t *painting_create(void)
{
    layer_t *layer = layer_create(sizeof(painting_t));

    if (!layer)
        return NULL;
    layer_bind_on_attach(layer, painting_on_attach);
    layer_bind_on_detach(layer, painting_on_detach);
    layer_bind_on_event(layer, painting_on_event);
    layer_bind_on_update(layer, painting_on_update);
    layer_bind_on_render(layer, painting_on_render);
    return layer;
}
