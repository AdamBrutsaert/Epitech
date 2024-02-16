/*
** EPITECH PROJECT, 2023
** player_create_animations.c
** File description:
** player_create_animations.c
*/

#include "entities/skeleton_impl.h"

static bool create_skeleton_animation(entity_skeleton_t *skeleton)
{
    skeleton->idle_animation = animation_new();
    skeleton->walk_animation = animation_new();
    skeleton->death_animation = animation_new();
    if (!skeleton->idle_animation || !skeleton->walk_animation
        || !skeleton->death_animation)
        return false;
    for (int i = 0; i < 4; i++)
        animation_add_frame(skeleton->idle_animation,
            (sfIntRect){i * 16, 0, 16, 16});
    for (int i = 0; i < 4; i++)
        animation_add_frame(skeleton->walk_animation,
            (sfIntRect){64 + i * 16, 0, 16, 16});
    for (int i = 0; i < 3; i++)
        animation_add_frame(skeleton->death_animation,
            (sfIntRect){i * 16, 0, 16, 16});
    animation_set_speed(skeleton->idle_animation, 6.0f);
    animation_set_speed(skeleton->walk_animation, 12.0f);
    animation_set_speed(skeleton->death_animation, 2.0f);
    animation_set_repeat(skeleton->death_animation, false);
    return true;
}

bool skeleton_create_animations(entity_t *entity)
{
    entity_skeleton_t *player = entity_get_data(entity);

    return create_skeleton_animation(player);
}
