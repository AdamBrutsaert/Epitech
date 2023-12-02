/*
** EPITECH PROJECT, 2023
** fireball.h
** File description:
** fireball.h
*/

#pragma once

#include "engine.h"

/**
 * @brief Allocate a new fireball entity
 *
 * @return entity_t* the entity
 */
entity_t *entity_fireball_new(entity_t *player);

void entity_fireball_set_position(entity_t *entity, float x, float y);
void entity_fireball_set_movement(entity_t *entity, float dx, float dy);
