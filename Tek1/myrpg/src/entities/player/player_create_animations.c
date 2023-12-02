/*
** EPITECH PROJECT, 2023
** player_create_animations.c
** File description:
** player_create_animations.c
*/

#include "entities/player_impl.h"

static bool create_player_animation(player_t *player)
{
    player->idle_animation = animation_new();
    player->walk_animation = animation_new();
    if (!player->idle_animation || !player->walk_animation)
        return false;
    for (int i = 0; i < 4; i++)
        animation_add_frame(
            player->idle_animation,
            (sfIntRect){i * 16, 0, 16, 28}
        );
    for (int i = 0; i < 4; i++)
        animation_add_frame(
            player->walk_animation,
            (sfIntRect){64 + i * 16, 0, 16, 28}
        );
    animation_set_speed(player->idle_animation, 6.0f);
    animation_set_speed(player->walk_animation, 12.0f);
    return true;
}

bool player_create_animations(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    return create_player_animation(player);
}
