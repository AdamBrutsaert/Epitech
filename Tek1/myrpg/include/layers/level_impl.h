/*
** EPITECH PROJECT, 2023
** level_impl.h
** File description:
** level_impl.h
*/

#pragma once

#include "level.h"

#include <SFML/Audio.h>

typedef struct {
    entity_t *player;
    sfRectangleShape *shape;
    sfMusic *music;
    bool is_paused;
} level_t;

bool layer_level_on_attach(layer_t *layer);
void layer_level_on_detach(layer_t *layer);
bool layer_level_on_event(layer_t *layer, sfEvent *event);
bool layer_level_on_update(layer_t *layer, float dt);
void layer_level_on_render(layer_t *layer);

bool add_skeleton(layer_t *layer, sfVector2f pos);
