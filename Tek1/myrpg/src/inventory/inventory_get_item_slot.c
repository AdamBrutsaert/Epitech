/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_get_item_slot
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

uint16_t inventory_get_item_slot(inventory_t *inventory, item_type_t type)
{
    for (uint16_t i = 0; i < inventory->size; i++) {
        if (inventory->items[i] && inventory->items[i]->type == type)
            return i;
    }
    return 0;
}
