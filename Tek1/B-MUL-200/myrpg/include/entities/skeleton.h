/*
** EPITECH PROJECT, 2023
** skeleton.h
** File description:
** skeleton.h
*/

#pragma once

#include "engine.h"

/**
 * @brief Allocate a new skeleton entity
 *
 * @return entity_t* the entity
 */
entity_t *entity_skeleton_new(sfVector2f pos);

void skeleton_kill(entity_t *entity);
