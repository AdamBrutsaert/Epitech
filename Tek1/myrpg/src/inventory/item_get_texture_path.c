/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** iitem_get_texture_path
*/

#include "rpg.h"
#include "inventory/inventory_impl.h"

char *item_get_texture_path(item_type_t type)
{
    if (type == ITEM_FLASK_RED)
        return RES("items/flask_big_red.png");
    if (type == ITEM_FLASK_YELLOW)
        return RES("items/flask_big_yellow.png");
    return NULL;
}
