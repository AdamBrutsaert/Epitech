/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#pragma once

#include "rpg.h"
#include "inventory/inventory.h"

struct item {
    sfTexture *texture;
    item_type_t type;
    void *data;
};

struct inventory {
    item_t **items;
    uint16_t size;
    bool should_update;
};

char *item_get_texture_path(item_type_t type);
