/*
** EPITECH PROJECT, 2023
** player_update_textures.c
** File description:
** player_update_textures.c
*/

#include "entities/player_impl.h"

static void update_animations(player_t *player, float dt)
{
    sfIntRect *rect;

    if (player->state == IDLE) {
        rect = animation_update(player->idle_animation, dt);;
        sfSprite_setTextureRect(player->sprite, *rect);
    }
    if (player->state == WALK) {
        rect = animation_update(player->walk_animation, dt);
        sfSprite_setTextureRect(player->sprite, *rect);
    }
}

static void update_direction(player_t *player)
{
    if (player->direction == LEFT) {
        sfSprite_setScale(player->sprite, (sfVector2f){-1, 1});
        sfSprite_setOrigin(player->sprite, (sfVector2f){16, 0});
    }
    if (player->direction == RIGHT) {
        sfSprite_setScale(player->sprite, (sfVector2f){1, 1});
        sfSprite_setOrigin(player->sprite, (sfVector2f){0, 0});
    }
}

void player_update_textures(entity_t *entity, float dt)
{
    player_t *player = entity_get_data(entity);

    update_animations(player, dt);
    update_direction(player);
}
