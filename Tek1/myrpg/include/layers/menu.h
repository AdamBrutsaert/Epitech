/*
** EPITECH PROJECT, 2023
** menu.h
** File description:
** menu.h
*/

#pragma once

#include "engine.h"

typedef struct menu menu_t;

#define ENTITY_MENU_FONT_PATH "res/font/dogica.ttf"

/**
 * @brief Create a new menu layer
 *
 * @return layer_t* the layer
 */
layer_t *menu_new(void);
