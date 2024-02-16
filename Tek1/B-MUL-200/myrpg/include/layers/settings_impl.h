/*
** EPITECH PROJECT, 2023
** settings_impl.h
** File description:
** settings_impl.h
*/

#pragma once

#include "settings.h"

typedef struct {
    layer_t *level;
    sfFont *font;

    entity_t *resume;
    entity_t *save;
    entity_t *config;
    entity_t *quit;
    entity_t *load;
} layer_settings_t;

bool layer_settings_on_attach(layer_t *layer);
void layer_settings_on_detach(layer_t *layer);
bool layer_settings_on_event(layer_t *layer, sfEvent *event);
bool layer_settings_on_update(layer_t *layer, float dt);
void layer_settings_on_render(layer_t *layer);

bool layer_settings_add_buttons(layer_t *layer);
void layer_settings_on_resume_clicked(entity_t *entity, void *data);
void layer_settings_on_quit_clicked(entity_t *entity, void *data);
void layer_settings_on_save_clicked(entity_t *entity, void *data);
void layer_settings_on_config_clicked(entity_t *entity, void *data);
void layer_settings_on_load_clicked(entity_t *entity, void *data);
