/*
** EPITECH PROJECT, 2023
** player_take_damage.c
** File description:
** player_take_damage.c
*/

#include "entities/player_impl.h"

void player_take_damage(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    player->life -= !!player->life;
    if (player->life > 0)
        sfSound_play(player->hit_sound);
    if (player->life == 0 && player->state != DEAD) {
        sfSound_play(player->death_sound);
        entity_remove_hitbox(entity, 0);
        sfSprite_setTextureRect(player->sprite, (sfIntRect){128,0,16,28});
        player->state = DEAD;
    }
}
