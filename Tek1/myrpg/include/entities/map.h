/*
** EPITECH PROJECT, 2023
** map.h
** File description:
** map.h
*/

#pragma once

#include "engine.h"

/**
 * @brief Allocate a new map entity
 *
 * @return entity_t* the entity
 */
entity_t *entity_map_new(const char *map, const char *collisions);
