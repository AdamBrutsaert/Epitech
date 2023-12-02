/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_play_click
*/

#include "rpg.h"
#include "entities/button.h"
#include "layers/config.h"

void button_menu_config_clicked(entity_t *entity, void *data)
{
    layer_t *layer = layer_config_new();

    if (layer == NULL)
        return;
    engine_push_layer(entity_get_engine(entity), layer);
}
