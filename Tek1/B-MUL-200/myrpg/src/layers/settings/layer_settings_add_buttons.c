/*
** EPITECH PROJECT, 2023
** layer_settings_add_buttons.c
** File description:
** layer_settings_add_buttons.c
*/

#include "layers/settings_impl.h"
#include "entities/button.h"

static bool add_resume(layer_t *layer, layer_settings_t *settings,
    sfVector2u size)
{
    entity_t *resume = button_new(layer_settings_on_resume_clicked,
        BUTTON_SKIN_BROWN, 8, settings->font);

    if (!resume || !layer_add_entity(layer, resume))
        return false;
    button_set_position(resume, size.x / 2.0f - 203, size.y / 2.0f - 50);
    button_set_string(resume, "Resume");
    settings->resume = resume;
    return true;
}

static bool add_save_load(layer_t *layer, layer_settings_t *settings,
    sfVector2u size)
{
    entity_t *save = button_new(layer_settings_on_save_clicked,
        BUTTON_SKIN_BROWN, 8, settings->font);
    entity_t *load = button_new(layer_settings_on_load_clicked,
        BUTTON_SKIN_BROWN, 8, settings->font);

    if (!save || !load || !layer_add_entity(layer, save)
        || !layer_add_entity(layer, load))
        return false;
    button_set_position(save, size.x / 2.0f - 203, size.y / 2.0f);
    button_set_string(save, "Save");
    button_set_position(load, size.x / 2.0f - 203, size.y / 2.0f + 50.0f);
    button_set_string(load, "Load");
    settings->save = save;
    settings->load = load;
    return true;
}

static bool add_config(layer_t *layer, layer_settings_t *settings,
    sfVector2u size)
{
    entity_t *config = button_new(layer_settings_on_config_clicked,
        BUTTON_SKIN_BROWN, 8, settings->font);

    if (!config || !layer_add_entity(layer, config))
        return false;
    button_set_position(config, size.x / 2.0f - 203, size.y / 2.0f + 100.0f);
    button_set_string(config, "Configuration");
    settings->config = config;
    return true;
}

static bool add_quit(layer_t *layer, layer_settings_t *settings,
    sfVector2u size)
{
    entity_t *quit = button_new(layer_settings_on_quit_clicked,
        BUTTON_SKIN_BROWN, 8, settings->font);

    if (!quit || !layer_add_entity(layer, quit))
        return false;
    button_set_position(quit, size.x / 2.0f - 203, size.y / 2.0f + 150.0f);
    button_set_string(quit, "Quit");
    settings->quit = quit;
    return true;
}

bool layer_settings_add_buttons(layer_t *layer)
{
    layer_settings_t *settings = layer_get_data(layer);
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));

    return add_resume(layer, settings, size)
        && add_quit(layer, settings, size)
        && add_save_load(layer, settings, size)
        && add_config(layer, settings, size);
}
