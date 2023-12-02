/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory_new
*/

#include <stdlib.h>

#include "rpg.h"
#include "inventory/inventory_impl.h"
#include "my/memory.h"

inventory_t *inventory_new(uint16_t size)
{
    inventory_t *inventory = my_calloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    inventory->items = my_calloc(sizeof(item_t) * (size + 1));
    inventory->size = size;
    if (!inventory->items) {
        free(inventory);
        return NULL;
    }
    return inventory;
}
