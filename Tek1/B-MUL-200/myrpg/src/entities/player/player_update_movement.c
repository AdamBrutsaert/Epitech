/*
** EPITECH PROJECT, 2023
** player_update_movement.c
** File description:
** player_update_movement.c
*/

#include "entities/player_impl.h"

void player_update_movement(entity_t *entity, float dt)
{
    float dx;
    float dy;

    player_get_movement(entity, &dx, &dy);
    if (player_update_position(entity, dx, dy, dt))
        player_update_state(entity, dx, dy);
    player_update_weapon_position(entity);
    player_update_camera(entity, dx, dy, dt);
}
