/*
** EPITECH PROJECT, 2023
** layer_settings_on_clicked.c
** File description:
** layer_settings_on_clicked.c
*/

#include "layers/settings_impl.h"
#include "layers/level_impl.h"
#include "layers/config.h"
#include "save.h"

void layer_settings_on_resume_clicked(entity_t *entity, void *data)
{
    layer_settings_t *settings = layer_get_data(entity_get_layer(entity));
    level_t *level = layer_get_data(settings->level);

    level->is_paused = false;
    engine_pop_layer(entity_get_engine(entity));
}

void layer_settings_on_quit_clicked(entity_t *entity, void *data)
{
    rpg_switch_to_menu(entity_get_engine(entity));
}

void layer_settings_on_save_clicked(entity_t *entity, void *data)
{
    save_write();
}

void layer_settings_on_config_clicked(entity_t *entity, void *data)
{
    layer_t *layer = layer_config_new();

    if (!layer)
        return;
    engine_push_layer(entity_get_engine(entity), layer);
}

void layer_settings_on_load_clicked(entity_t *entity, void *data)
{
    save_read();
    rpg_switch_to_level(entity_get_engine(entity));
}
