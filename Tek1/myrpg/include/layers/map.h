/*
** EPITECH PROJECT, 2023
** map.h
** File description:
** map.h
*/

#pragma once

#include "engine.h"

/**
 * @brief Allocate a new map layer
 *
 * @return layer_t* the layer
 */
layer_t *layer_map_new(const char *map, const char *collisions);

void layer_map_set_level_layer(layer_t *layer, layer_t *level);
