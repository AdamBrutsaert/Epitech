/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** item_destroy
*/

#include <stdlib.h>

#include "rpg.h"
#include "inventory/inventory_impl.h"

void item_destroy(item_t *item)
{
    if (!item)
        return;
    sfTexture_destroy(item->texture);
    free(item);
}
