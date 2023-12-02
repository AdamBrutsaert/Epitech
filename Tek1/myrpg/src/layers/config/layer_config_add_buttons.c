/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** layer_config_add_buttons
*/

#include "rpg.h"
#include "entities/button_impl.h"
#include "layers/config_impl.h"

static bool create_dimension_buttons(layer_t *layer, layer_config_t *config)
{
    config->dim_one_button = button_new(button_config_1280_clicked,
        BUTTON_SKIN_BROWN, 4, config->font);
    if (!config->dim_one_button || !layer_add_entity(layer,
        config->dim_one_button))
        return false;
    button_set_string(config->dim_one_button, "1280x720");
    config->dim_two_button = button_new(button_config_800_clicked,
        BUTTON_SKIN_BROWN, 4, config->font);
    if (!config->dim_two_button || !layer_add_entity(layer,
        config->dim_two_button))
        return false;
    button_set_string(config->dim_two_button, "1920x1080");
    return true;
}

static bool create_fullscreen_button(layer_t *layer, layer_config_t *config)
{
    config->fullscreen_button = button_new(button_config_fullscreen_clicked,
        BUTTON_SKIN_BROWN, 8, config->font);
    if (!config->fullscreen_button || !layer_add_entity(layer,
        config->fullscreen_button))
        return false;
    button_set_string(config->fullscreen_button, "Toggle fullscreen");
    return true;
}

static bool create_previous_button(layer_t *layer, layer_config_t *config)
{
    config->previous_button = button_new(button_config_previous_clicked,
        BUTTON_SKIN_BROWN, 4, config->font);
    if (!config->previous_button || !layer_add_entity(layer,
        config->previous_button))
        return false;
    button_set_string(config->previous_button, "Previous");
    return true;
}

bool layer_config_add_buttons(layer_t *layer, layer_config_t *config)
{
    if (!create_dimension_buttons(layer, config)
        || !create_fullscreen_button(layer, config)
        || !create_previous_button(layer, config))
        return false;
    layer_config_center_buttons(layer);
    button_hcenter(config->dim_one_button);
    button_hcenter(config->dim_two_button);
    button_hcenter(config->fullscreen_button);
    button_hcenter(config->previous_button);
    return true;
}
