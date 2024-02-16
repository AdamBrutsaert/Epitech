/*
** EPITECH PROJECT, 2023
** menu_create.c
** File description:
** menu_create.c
*/

#include "private/paint/layers/menu.h"

layer_t *menu_create(void)
{
    layer_t *layer = layer_create(sizeof(menu_t));

    if (!layer)
        return NULL;
    layer_bind_on_attach(layer, menu_on_attach);
    layer_bind_on_detach(layer, menu_on_detach);
    layer_bind_on_event(layer, menu_on_event);
    layer_bind_on_render(layer, menu_on_render);
    return layer;
}
