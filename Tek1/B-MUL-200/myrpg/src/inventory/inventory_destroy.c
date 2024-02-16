/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_destroy
*/

#include <stdlib.h>

#include "rpg.h"
#include "inventory/inventory_impl.h"

void inventory_destroy(inventory_t *inventory)
{
    if (!inventory)
        return;
    for (uint16_t i = 0; i < inventory->size; i++)
        item_destroy(inventory->items[i]);
    free(inventory->items);
    free(inventory);
}
