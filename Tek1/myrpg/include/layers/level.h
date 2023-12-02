/*
** EPITECH PROJECT, 2023
** level.h
** File description:
** level.h
*/

#pragma once

#include "engine.h"
#include "entities/player.h"

/**
 * @brief Allocate a new level layer
 *
 * @return layer_t* the layer
*/
layer_t *level_new(void);

/**
 * @brief Get the player entity
 *
 * @param layer the level layer
 * @return entity_t* the player entity
*/
entity_t *level_get_player(layer_t *layer);

sfView *level_get_view(layer_t *layer);
