/*
** EPITECH PROJECT, 2023
** map_impl.h
** File description:
** map_impl.h
*/

#pragma once

#include "map.h"

typedef struct {
    const char *map;
    const char *collisions;
    layer_t *layer;
} layer_map_t;

bool layer_map_on_attach(layer_t *layer);
void layer_map_on_detach(layer_t *layer);
bool layer_map_on_event(layer_t *layer, sfEvent *event);
bool layer_map_on_update(layer_t *layer, float dt);
void layer_map_on_render(layer_t *layer);
