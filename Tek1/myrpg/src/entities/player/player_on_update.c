/*
** EPITECH PROJECT, 2023
** player_on_update.c
** File description:
** player_on_update.c
*/

#include "entities/player_impl.h"

bool player_on_update(entity_t *entity, float dt)
{
    player_t *player = entity_get_data(entity);

    if (player->state == DEAD) {
        player->death_cooldown += dt;
        if (player->death_cooldown >= DEATH_COOLDOWN)
            rpg_switch_to_menu(entity_get_engine(entity));
        return true;
    }
    player_update_textures(entity, dt);
    if (player_is_paused(entity))
        return true;
    player_update_movement(entity, dt);
    player->cooldown -= dt;
    if (player->cooldown < 0)
        player->cooldown = 0;
    player->sound_cooldown -= dt;
    if (player->sound_cooldown < 0)
        player->sound_cooldown = 0;
    return true;
}
