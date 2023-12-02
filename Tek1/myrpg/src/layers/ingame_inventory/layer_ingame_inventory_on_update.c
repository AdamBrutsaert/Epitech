/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_on_update.c
** File description:
** layer_ingame_inventory_on_update.c
*/

#include "layers/ingame_inventory_impl.h"
#include "inventory/inventory_impl.h"
#include "layers/level.h"
#include "entities/text.h"

static void add_text(layer_t *layer)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);
    entity_t *text;

    i->font = sfFont_createFromFile("res/font/dogica.ttf");
    if (!i->font)
        return;
    text = text_new(i->font);
    if (text == NULL)
        return;
    if (!layer_add_entity(layer, text))
        entity_delete(text);
    text_set_string(text, "Quest completed!");
    text_set_size(text, 16);
    text_set_position(text, (sfVector2f){380, 30});
}

bool layer_ingame_inventory_on_update(layer_t *layer, float dt)
{
    layer_ingame_inventory_t *i = layer_get_data(layer);
    entity_t *player = level_get_player(i->level);

    if (player_has_all(player) && !i->has_added_text) {
        i->has_added_text = true;
        add_text(layer);
    }
    if (i->inventory->should_update) {
        i->inventory->should_update = false;
        return layer_ingame_inventory_update(layer);
    }
    return true;
}
