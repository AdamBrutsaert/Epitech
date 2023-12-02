/*
** EPITECH PROJECT, 2023
** characteristics.h
** File description:
** characteristics.h
*/

#pragma once

#include "engine.h"

/**
 * @brief Allocate a new characteristics layer
 *
 * @return layer_t* the layer
 */
layer_t *layer_characteristics_new(void);

void layer_characteristics_set_level(layer_t *layer, layer_t *level);
