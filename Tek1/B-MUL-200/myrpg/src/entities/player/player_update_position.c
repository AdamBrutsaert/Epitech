/*
** EPITECH PROJECT, 2023
** player_update_position.c
** File description:
** player_update_position.c
*/

#include "entities/player_impl.h"
#include "my/string.h"

static void play_sound(player_t *player)
{
    if (player->sound_cooldown == 0) {
        sfSound_play(player->sound);
        player->sound_cooldown = SOUND_COOLDOWN;
    }
}

static bool move_x(
    entity_t *entity,
    sfVector2f *position,
    sfFloatRect *hitbox,
    float delta
)
{
    entity_t *colliding;

    if (delta == 0)
        return false;
    hitbox->left += delta;
    colliding = engine_is_colliding(entity_get_engine(entity), entity);
    if (colliding != NULL
        && my_strcmp(entity_get_type(colliding), "Fireball")) {
        hitbox->left -= delta;
        return false;
    }
    position->x += delta;
    return true;
}

static bool move_y(
    entity_t *entity,
    sfVector2f *position,
    sfFloatRect *hitbox,
    float delta
)
{
    entity_t *colliding;

    if (delta == 0)
        return false;
    hitbox->top += delta;
    colliding = engine_is_colliding(entity_get_engine(entity), entity);
    if (colliding != NULL
        && my_strcmp(entity_get_type(colliding), "Fireball")) {
        hitbox->top -= delta;
        return false;
    }
    position->y += delta;
    return true;
}

bool player_update_position(entity_t *entity, float dx, float dy, float dt)
{
    player_t *player = entity_get_data(entity);
    sfVector2f position = sfSprite_getPosition(player->sprite);
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    bool has_moved;

    has_moved = move_x(entity, &position, hitbox, dx * dt);
    has_moved = move_y(entity, &position, hitbox, dy * dt) || has_moved;
    sfSprite_setPosition(player->sprite, position);
    if (has_moved)
        play_sound(player);
    return has_moved;
}
