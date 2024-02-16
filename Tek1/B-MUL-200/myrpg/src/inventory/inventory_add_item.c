/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_add_item
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

bool inventory_add_item(inventory_t *inventory, item_t *item)
{
    if (inventory_has_item(inventory, item->type)
        || inventory_is_full(inventory))
        return false;
    for (uint16_t i = 0; i < inventory->size; i++) {
        if (inventory->items[i])
            continue;
        inventory->items[i] = item;
        inventory->should_update = true;
        return true;
    }
    return false;
}
