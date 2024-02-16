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

static void create_view(layer_t *layer, layer_ingame_inventory_t *i)
{
    sfVector2u window_size = sfRenderWindow_getSize(layer_get_window(i->level));
    sfView *view = layer_get_view(layer);

    sfView_setSize(view, (sfVector2f) {window_size.x, window_size.y});
    sfView_setCenter(view, (sfVector2f) {window_size.x / 2,
        window_size.y / 2});
}

bool layer_ingame_inventory_on_attach(layer_t *layer)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);
    entity_t *player = level_get_player(i->level);

    i->item_slot_texture = sfTexture_createFromFile(RES("ui/item_slot.png"),
        NULL);
    if (!i->item_slot_texture)
        return false;
    i->inventory = player_get_inventory(player);
    i->boxes = my_calloc(sizeof(sfSprite *) * (i->inventory->size + 1));
    i->items = my_calloc(sizeof(sfSprite *) * (i->inventory->size + 1));
    if (!i->boxes || !i->items)
        return false;
    layer_ingame_inventory_update(layer);
    layer_ingame_inventory_replace_items(layer);
    create_view(layer, i);
    return true;
}
