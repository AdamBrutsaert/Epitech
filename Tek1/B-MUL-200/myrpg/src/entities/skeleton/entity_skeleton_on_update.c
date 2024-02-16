/*
** EPITECH PROJECT, 2023
** entity_skeleton_on_update.c
** File description:
** entity_skeleton_on_update.c
*/

#include "entities/skeleton_impl.h"
#include "entities/player.h"
#include "my/string.h"

static void try_attack(entity_t *entity, float dt)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    sfVector2f pos = sfSprite_getPosition(skeleton->sprite);
    sfVector2f player = player_get_position(skeleton->player);
    sfVector2f distance = (sfVector2f){player.x - pos.x, player.y - pos.y};
    float len = distance.x * distance.x + distance.y * distance.y;

    if (len < 20 * 20 && skeleton->cooldown <= 0) {
        player_take_damage(skeleton->player);
        skeleton->cooldown = ATTACK_COOLDOWN;
    }
    skeleton->cooldown -= dt;
}

bool entity_skeleton_on_update(entity_t *entity, float dt)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    float dx;
    float dy;

    skeleton_get_movement(entity, &dx, &dy);
    skeleton_moves(entity, dt, &dx, &dy);
    if (!skeleton_update_movment(entity, dt))
        return true;
    if (skeleton->state != DYING)
        try_attack(entity, dt);
    return true;
}
