/*
** EPITECH PROJECT, 2023
** player_get_cooldown.c
** File description:
** player_get_cooldown.c
*/

#include "entities/player_impl.h"

float player_get_cooldown(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    return COOLDOWN - player->strength * COOLDOWN_PER_STRENGTH;
}
