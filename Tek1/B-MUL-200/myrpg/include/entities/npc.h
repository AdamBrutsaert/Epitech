/*
** EPITECH PROJECT, 2023
** npc.h
** File description:
** npc.h
*/

#pragma once

#include "engine.h"

#define NPC_TRIGGER_DISTANCE 100

/**
 * @brief Allocate a new npc entity
 *
 * @return entity_t* the entity
 */
entity_t *entity_npc_new(entity_t *player, const char *string, sfVector2f pos);
