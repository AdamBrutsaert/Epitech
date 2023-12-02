/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_on_detach.c
** File description:
** layer_ingame_inventory_on_detach.c
*/

#include <stdlib.h>

#include "layers/ingame_inventory_impl.h"

void layer_ingame_inventory_on_detach(layer_t *layer)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);

    for (int j = 0; j < i->inventory->size; j++) {
        if (i->boxes)
            sfSprite_destroy(i->boxes[j]);
        if (i->items)
            sfSprite_destroy(i->items[j]);
    }
    if (i->boxes)
        free(i->boxes);
    if (i->items)
        free(i->items);
    sfFont_destroy(i->font);
    sfTexture_destroy(i->item_slot_texture);
}
