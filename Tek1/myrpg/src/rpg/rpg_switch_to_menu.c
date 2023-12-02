/*
** EPITECH PROJECT, 2023
** rpg_switch_to_menu.c
** File description:
** rpg_switch_to_menu.c
*/

#include "rpg.h"

#include "layers/menu.h"

bool rpg_switch_to_menu(engine_t *engine)
{
    layer_t *menu = menu_new();

    if (menu == NULL)
        return false;
    if (!engine_clear_layers(engine) || !engine_push_layer(engine, menu)) {
        layer_delete(menu);
        return false;
    }
    return true;
}
