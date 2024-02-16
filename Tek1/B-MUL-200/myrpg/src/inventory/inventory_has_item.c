/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_has_item
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

bool inventory_has_item(inventory_t *inventory, item_type_t type)
{
    for (uint16_t i = 0; i < inventory->size; i++) {
        if (inventory->items[i] && inventory->items[i]->type == type)
            return true;
    }
    return false;
}
