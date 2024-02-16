/*
** EPITECH PROJECT, 2023
** entity_fireball_on_update.c
** File description:
** entity_fireball_on_update.c
*/

#include "entities/fireball_impl.h"
#include "entities/skeleton.h"
#include "entities/player.h"
#include "my/string.h"

static void update_texture(entity_fireball_t *fireball, float dt)
{
    sfIntRect *rect;

    if (fireball->is_destroyed) {
        rect = animation_update(fireball->destroying, dt);
    } else {
        rect = animation_update(fireball->animation, dt);
    }
    sfSprite_setTextureRect(fireball->sprite, *rect);
}

static bool on_collision(entity_t *entity, entity_t *colliding)
{
    entity_fireball_t *fireball = entity_get_data(entity);

    if (!my_strcmp(entity_get_type(colliding), "Skeleton")) {
        skeleton_kill(colliding);
        player_level_up(fireball->player);
    }
    fireball->is_destroyed = true;
    entity_remove_hitbox(entity, 0);
    sfSound_play(fireball->boom);
    return true;
}

static bool update_position(entity_t *entity, float dt)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    sfVector2f position = sfSprite_getPosition(fireball->sprite);
    engine_t *engine = entity_get_engine(entity);
    entity_t *colliding;

    hitbox->left += fireball->movement.x * FIREBALL_SPEED * dt;
    hitbox->top += fireball->movement.y * FIREBALL_SPEED * dt;
    colliding = engine_is_colliding(engine, entity);
    if (colliding != NULL && my_strcmp(entity_get_type(colliding), "Player"))
        return on_collision(entity, colliding);
    position.x += fireball->movement.x * FIREBALL_SPEED * dt;
    position.y += fireball->movement.y * FIREBALL_SPEED * dt;
    sfSprite_setPosition(fireball->sprite, position);
    return true;
}

bool entity_fireball_on_update(entity_t *entity, float dt)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    layer_t *layer = entity_get_layer(entity);

    update_texture(fireball, dt);
    if (fireball->is_destroyed && animation_is_over(fireball->destroying)) {
        layer_remove_entity(layer, entity);
        return true;
    }
    if (fireball->is_destroyed)
        return true;
    return update_position(entity, dt);
}
