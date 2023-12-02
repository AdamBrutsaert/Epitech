/*
** EPITECH PROJECT, 2023
** layer_config_center_buttons.c
** File description:
** layer_config_center_buttons.c
*/

#include "layers/config_impl.h"
#include "entities/button.h"

void layer_config_center_buttons(layer_t *layer)
{
    layer_config_t *config = layer_get_data(layer);
    sfVector2u window_size = sfRenderWindow_getSize(layer_get_window(layer));

    button_set_position(config->dim_one_button, window_size.x / 2 - 203,
        window_size.y / 2 - 42 / 2);
    button_set_position(config->dim_two_button, window_size.x / 2 - 203,
        window_size.y / 2 - 42 / 2 + 50);
    button_set_position(config->fullscreen_button, window_size.x / 2 - 203,
        window_size.y / 2 - 42 / 2 + 100);
    button_set_position(config->previous_button, window_size.x / 2 - 203,
        window_size.y / 2 - 42 / 2 + 150);
    button_hcenter(config->dim_one_button);
    button_hcenter(config->dim_two_button);
    button_hcenter(config->fullscreen_button);
    button_hcenter(config->previous_button);
}
