/*
** EPITECH PROJECT, 2023
** config_impl.h
** File description:
** config_impl.h
*/

#pragma once

#include "config.h"

typedef struct {
    sfFont *font;
    entity_t *dim_one_button;
    entity_t *dim_two_button;
    entity_t *fullscreen_button;
    entity_t *previous_button;
} layer_config_t;

bool layer_config_on_attach(layer_t *layer);
void layer_config_on_detach(layer_t *layer);
bool layer_config_on_event(layer_t *layer, sfEvent *event);
bool layer_config_on_update(layer_t *layer, float dt);
void layer_config_on_render(layer_t *layer);

bool layer_config_add_buttons(layer_t *layer, layer_config_t *config);

void layer_config_center_buttons(layer_t *layer);
void button_config_1280_clicked(entity_t *entity, void *data);
void button_config_800_clicked(entity_t *entity, void *data);
void button_config_fullscreen_clicked(entity_t *entity, void *data);
void button_config_previous_clicked(entity_t *entity, void *data);
