/*
** EPITECH PROJECT, 2023
** menu_new.c
** File description:
** menu_new.c
*/

#include "layers/menu_impl.h"

layer_t *menu_new(void)
{
    layer_t *layer = layer_new(sizeof(menu_t));

    if (layer == NULL)
        return NULL;
    layer_bind_on_attach(layer, menu_on_attach);
    layer_bind_on_detach(layer, menu_on_detach);
    layer_bind_on_render(layer, menu_on_render);
    layer_bind_on_event(layer, menu_on_event);
    return layer;
}
