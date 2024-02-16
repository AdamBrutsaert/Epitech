/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** item_new
*/

#include <stdlib.h>

#include "rpg.h"
#include "inventory/inventory_impl.h"
#include "my/memory.h"

item_t *item_new(item_type_t type)
{
    item_t *item = my_calloc(sizeof(item_t));

    if (!item)
        return NULL;
    if (item_get_texture_path(type) == NULL) {
        item_destroy(item);
        return NULL;
    }
    item->type = type;
    item->texture = sfTexture_createFromFile(item_get_texture_path(type), NULL);
    return item;
}
