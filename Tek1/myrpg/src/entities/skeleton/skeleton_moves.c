/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** skeleton_movment
*/

#include "engine/entity.h"
#include "entities/skeleton_impl.h"
#include <math.h>

static void move_left(
    entity_t *entity,
    float dt,
    float *dx,
    sfVector2f *pos
)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    float move = SKELETON_SPEED * dt;

    hitbox->left -= move;
    if (engine_is_colliding(entity_get_engine(entity), entity) != NULL) {
        hitbox->left += move;
        return;
    }
    pos->x -= move;
    sfSprite_setScale(skeleton->sprite, (sfVector2f){-1, 1});
    sfSprite_setOrigin(skeleton->sprite, (sfVector2f){16, 0});
}

static void move_right(
    entity_t *entity,
    float dt,
    float *dx,
    sfVector2f *pos
)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    float move = SKELETON_SPEED * dt;

    hitbox->left += move;
    if (engine_is_colliding(entity_get_engine(entity), entity) != NULL) {
        hitbox->left -= move;
        return;
    }
    pos->x += move;
    sfSprite_setScale(skeleton->sprite, (sfVector2f){1, 1});
    sfSprite_setOrigin(skeleton->sprite, (sfVector2f){0, 0});
}

static void move_up(
    entity_t *entity,
    float dt,
    float *dy,
    sfVector2f *pos
)
{
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    float move = SKELETON_SPEED * dt;

    hitbox->top -= move;
    if (engine_is_colliding(entity_get_engine(entity), entity) != NULL) {
        hitbox->top += move;
        return;
    }
    pos->y -= move;
}

static void move_down(
    entity_t *entity,
    float dt,
    float *dy,
    sfVector2f *pos
)
{
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);
    float move = SKELETON_SPEED * dt;

    hitbox->top += move;
    if (engine_is_colliding(entity_get_engine(entity), entity) != NULL) {
        hitbox->top -= move;
        return;
    }
    pos->y += move;
}

void skeleton_moves(entity_t *entity, float dt, float *dx, float *dy)
{
    entity_skeleton_t *skeleton = entity_get_data(entity);
    sfVector2f pos = sfSprite_getPosition(skeleton->sprite);
    sfVector2f wizard_pos = player_get_position(skeleton->player);

    if (skeleton->state == DYING)
        return;
    if (pow(wizard_pos.x - pos.x, 2)
        + pow(wizard_pos.y - pos.y, 2) < 200 * 200) {
        if (wizard_pos.x > pos.x)
            move_right(entity, dt, dx, &pos);
        if (wizard_pos.x < pos.x)
            move_left(entity, dt, dx, &pos);
        if (wizard_pos.y > pos.y)
            move_down(entity, dt, dy, &pos);
        if (wizard_pos.y < pos.y)
            move_up(entity, dt, dy, &pos);
        skeleton->state = WALK;
        sfSprite_setPosition(skeleton->sprite, pos);
    } else
        skeleton->state = IDLE;
}
