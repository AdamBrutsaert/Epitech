/*
** EPITECH PROJECT, 2023
** player.h
** File description:
** player.h
*/

#pragma once

#include "engine.h"
#include "inventory/inventory.h"

#define PLAYER_INVENTORY_SIZE 5

typedef struct player player_t;

/**
 * @brief Allocate a new player entity
 *
 * @return entity_t* the new entity
 */
entity_t *player_new(void);

/**
 * @brief Get the player view
 *
 * @return sfView* the view
 */
sfView *player_get_view(entity_t *entity);

/**
 * @brief Get the player inventory
 *
 * @param entity the player entity
 * @return inventory_t* the inventory
*/
inventory_t *player_get_inventory(entity_t *entity);

void player_take_damage(entity_t *entity);
void player_level_up(entity_t *entity);
bool player_has_all(entity_t *entity);
