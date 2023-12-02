/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_update.c
** File description:
** layer_ingame_inventory_update.c
*/

#include "layers/ingame_inventory_impl.h"

static sfSprite *create_box(layer_ingame_inventory_t *i, uint16_t c)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, i->item_slot_texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    return sprite;
}

static sfSprite *create_item(layer_ingame_inventory_t *i, uint16_t c)
{
    sfSprite *sprite;
    item_t *item = inventory_get_item(i->inventory, c);

    if (!item)
        return NULL;
    sprite = sfSprite_create();
    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, item->texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    return sprite;
}

bool layer_ingame_inventory_update(layer_t *layer)
{
    layer_ingame_inventory_t *self = layer_get_data(layer);

    for (int j = 0; j < self->inventory->size; j++) {
        if (self->boxes && self->boxes[j])
            sfSprite_destroy(self->boxes[j]);
        if (self->items && self->items[j])
            sfSprite_destroy(self->items[j]);
        self->boxes[j] = create_box(self, j);
        self->items[j] = create_item(self, j);
    }
    layer_ingame_inventory_replace_items(layer);
    return true;
}
