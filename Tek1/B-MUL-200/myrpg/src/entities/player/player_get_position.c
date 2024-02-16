/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** player_get_position
*/

#include "entities/player_impl.h"

sfVector2f player_get_position(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    return sfSprite_getPosition(player->sprite);
}
