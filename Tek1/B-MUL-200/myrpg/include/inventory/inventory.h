/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#pragma once

#include "rpg.h"

typedef struct item item_t;
typedef struct inventory inventory_t;

typedef enum {
    ITEM_FLASK_RED = 0,
    ITEM_FLASK_YELLOW
} item_type_t;

/**
 * @brief Create a new item
 *
 * @param type the type of the item
*/
item_t *item_new(item_type_t type);

/**
 * @brief Destroy an item
 *
 * @param item the item to destroy
*/
void item_destroy(item_t *item);

/**
 * @brief Create a new inventory
 *
 * @param size the size of the inventory
 * @return inventory_t* the new inventory
*/
inventory_t *inventory_new(uint16_t size);

void inventory_destroy(inventory_t *inventory);

/**
 * @brief Add an item to the specified inventory
 *
 * @param inventory the inventory to add the item to
 * @param item the item to add
 * @return true if the item was added successfully
*/
bool inventory_add_item(inventory_t *inventory, item_t *item);

/**
 * @brief Get the item at the specified slot in the inventory
 *
 * @param inventory the inventory to get the item from
 * @param slot the slot to get the item from
 * @return item_t* the item at the specified slot
*/
item_t *inventory_get_item(inventory_t *inventory, uint16_t slot);

uint16_t inventory_get_item_slot(inventory_t *inventory, item_type_t type);

bool inventory_has_item(inventory_t *inventory, item_type_t type);

bool inventory_is_full(inventory_t *inventory);

bool inventory_should_update(inventory_t *inventory);
