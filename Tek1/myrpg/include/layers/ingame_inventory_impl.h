/*
** EPITECH PROJECT, 2023
** ingame_inventory_impl.h
** File description:
** ingame_inventory_impl.h
*/

#pragma once

#include "inventory/inventory_impl.h"
#include "layers/ingame_inventory.h"

typedef struct {
    layer_t *level;
    inventory_t *inventory;
    sfTexture *item_slot_texture;
    sfSprite **boxes;
    sfSprite **items;
    bool has_added_text;
    sfFont *font;
} layer_ingame_inventory_t;

bool layer_ingame_inventory_on_attach(layer_t *layer);
void layer_ingame_inventory_on_detach(layer_t *layer);
bool layer_ingame_inventory_on_event(layer_t *layer, sfEvent *event);
bool layer_ingame_inventory_on_update(layer_t *layer, float dt);
void layer_ingame_inventory_on_render(layer_t *layer);
