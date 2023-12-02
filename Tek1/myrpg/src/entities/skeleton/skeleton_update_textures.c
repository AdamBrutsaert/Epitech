/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** skeleton_update_textures
*/

#include "entities/skeleton_impl.h"

static void update_animations(entity_skeleton_t *skeleton, float dt)
{
    sfIntRect *rect;

    if (skeleton->state == IDLE) {
        rect = animation_update(skeleton->idle_animation, dt);
        sfSprite_setTextureRect(skeleton->sprite, *rect);
    }
    if (skeleton->state == WALK) {
        rect = animation_update(skeleton->walk_animation, dt);
        sfSprite_setTextureRect(skeleton->sprite, *rect);
    }
    if (skeleton->state == DYING) {
        rect = animation_update(skeleton->death_animation, dt);
        sfSprite_setTextureRect(skeleton->sprite, *rect);
    }
}

bool skeleton_update_movment(entity_t *entity, float dt)
{
    layer_t *layer = entity_get_layer(entity);
    entity_skeleton_t *skeleton = entity_get_data(entity);

    if (skeleton->state == DYING
        && animation_is_over(skeleton->death_animation)) {
        layer_remove_entity(layer, entity);
        return false;
    }
    update_animations(skeleton, dt);
    return true;
}
