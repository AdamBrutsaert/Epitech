/*
** EPITECH PROJECT, 2023
** characteristics_impl.h
** File description:
** characteristics_impl.h
*/

#pragma once

#include "characteristics.h"

typedef struct {
    layer_t *level;
    sfTexture *texture;
    sfSprite **hearts;
    uint32_t max_life;
    uint32_t life;
} layer_characteristics_t;

bool layer_characteristics_on_attach(layer_t *layer);
void layer_characteristics_on_detach(layer_t *layer);
bool layer_characteristics_on_event(layer_t *layer, sfEvent *event);
bool layer_characteristics_on_update(layer_t *layer, float dt);
void layer_characteristics_on_render(layer_t *layer);
