/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_on_attach.c
** File description:
** layer_ingame_inventory_on_attach.c
*/

#include <stdlib.h>

#include "my/memory.h"
#include "layers/ingame_inventory_impl.h"
#include "inventory/inventory.h"
#include "layers/level.h"

void layer_ingame_inventory_replace_items(layer_t *layer)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);
    sfSprite *sprite;
    sfVector2u texture_bounds = sfTexture_getSize(i->item_slot_texture);

    for (uint16_t c = 0; c < i->inventory->size; c++) {
        sprite = i->boxes[c];
        sfSprite_setPosition(sprite, (sfVector2f){
            SPACE_UPPER + (c * (SPACE_BETWEEN_BOXES + texture_bounds.x)),
                SPACE_UPPER
        });
        sprite = i->items[c];
        if (sprite == NULL)
            continue;
        sfSprite_setPosition(sprite, (sfVector2f){
            SPACE_UPPER + (c * (SPACE_BETWEEN_BOXES + texture_bounds.x)),
                SPACE_UPPER
        });
    }
}
