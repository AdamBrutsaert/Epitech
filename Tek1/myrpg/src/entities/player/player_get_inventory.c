/*
** EPITECH PROJECT, 2023
** player_get_movement.c
** File description:
** player_get_movement.c
*/

#include "entities/player_impl.h"

inventory_t *player_get_inventory(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    return player->inventory;
}
