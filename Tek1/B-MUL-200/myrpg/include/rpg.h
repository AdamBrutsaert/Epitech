/*
** EPITECH PROJECT, 2023
** rpg.h
** File description:
** rpg.h
*/

#pragma once

#include "engine.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int rpg(void);

bool rpg_switch_to_menu(engine_t *engine);
bool rpg_switch_to_level(engine_t *engine);
