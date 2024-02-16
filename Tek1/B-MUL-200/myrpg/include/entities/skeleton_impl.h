/*
** EPITECH PROJECT, 2023
** skeleton_impl.h
** File description:
** skeleton_impl.h
*/

#pragma once

#include "skeleton.h"
#include "utils/animation.h"
#include "engine/entity_impl.h"

#include <SFML/Audio.h>

#define SKELETON_SPEED 45
#define ATTACK_COOLDOWN 1.0f

typedef enum {
    IDLE = 0,
    WALK,
    DYING,
} skeleton_state_t;

typedef struct {
    sfVector2f pos;
    sfTexture *texture;
    sfTexture *dying_texture;
    sfSprite *sprite;

    float cooldown;

    animation_t *idle_animation;
    animation_t *walk_animation;
    animation_t *death_animation;

    skeleton_state_t state;
    entity_t *player;

    bool is_dying;

    sfSound *death_sound;
    sfSoundBuffer *death_sound_buffer;
} entity_skeleton_t;

bool entity_skeleton_on_attach(entity_t *entity);
void entity_skeleton_on_detach(entity_t *entity);
bool entity_skeleton_on_event(entity_t *entity, sfEvent *event);
bool entity_skeleton_on_update(entity_t *entity, float dt);
void entity_skeleton_on_render(entity_t *entity);
bool skeleton_create_animations(entity_t *entity);
void skeleton_moves(entity_t *entity, float dt, float *dx, float *dy);
sfVector2f player_get_position(entity_t *entity);
void skeleton_get_movement(entity_t *entity, float *dx, float *dy);
bool animation_is_over(animation_t *animation);
bool skeleton_update_movment(entity_t *entity, float dt);
