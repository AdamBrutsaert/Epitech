/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_get_item
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

item_t *inventory_get_item(inventory_t *inventory, uint16_t slot)
{
    if (slot >= inventory->size)
        return NULL;
    return inventory->items[slot];
}
