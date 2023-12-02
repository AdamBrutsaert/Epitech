/*
** EPITECH PROJECT, 2023
** player_update_weapon_position.c
** File description:
** player_update_weapon_position.c
*/

#include "entities/player_impl.h"

void player_update_weapon_position(entity_t *entity)
{
    player_t *player = entity_get_data(entity);
    sfVector2f position = sfSprite_getPosition(player->sprite);

    position = sfSprite_getPosition(player->sprite);
    if (player->direction == LEFT) {
        sfSprite_setPosition(player->weapon, (sfVector2f){
            position.x - 4,
            position.y + 28
        });
    } else {
        sfSprite_setPosition(player->weapon, (sfVector2f){
            position.x + 20,
            position.y + 28
        });
    }
}
