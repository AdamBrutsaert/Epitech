/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_play_click
*/

#include "rpg.h"
#include "entities/button.h"
#include "save_impl.h"

void button_menu_play_clicked(entity_t *entity, void *data)
{
    save_default();
    rpg_switch_to_level(entity_get_engine(entity));
}
