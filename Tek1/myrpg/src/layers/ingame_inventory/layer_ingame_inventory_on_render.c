/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_on_render.c
** File description:
** layer_ingame_inventory_on_render.c
*/

#include "layers/ingame_inventory_impl.h"

void layer_ingame_inventory_on_render(layer_t *layer)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);

    for (uint16_t c = 0; c < i->inventory->size; c++) {
        sfRenderWindow_drawSprite(layer_get_window(layer), i->boxes[c], NULL);
        if (i->items[c] != NULL)
            sfRenderWindow_drawSprite(layer_get_window(layer), i->items[c],
                NULL);
    }
}
