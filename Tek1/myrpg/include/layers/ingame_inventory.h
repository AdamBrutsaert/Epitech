/*
** EPITECH PROJECT, 2023
** ingame_inventory.h
** File description:
** ingame_inventory.h
*/

#pragma once

#include "engine.h"
#include "inventory/inventory.h"

#define SPACE_BETWEEN_BOXES 12
#define SPACE_UPPER 12

/**
 * @brief Allocate a new ingame_inventory layer
 *
 * @return layer_t* the layer
 */
layer_t *layer_ingame_inventory_new(layer_t *level);

bool layer_ingame_inventory_update(layer_t *layer);

void layer_ingame_inventory_replace_items(layer_t *layer);
