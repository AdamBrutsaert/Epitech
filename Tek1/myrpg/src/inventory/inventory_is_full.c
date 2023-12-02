/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_has_item
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

bool inventory_is_full(inventory_t *inventory)
{
    for (uint16_t i = 0; i < inventory->size; i++) {
        if (!inventory->items[i])
            return false;
    }
    return true;
}
