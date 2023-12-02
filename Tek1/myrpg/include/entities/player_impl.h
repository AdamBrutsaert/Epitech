/*
** EPITECH PROJECT, 2023
** player_impl.h
** File description:
** player_impl.h
*/

#pragma once

#include "player.h"
#include "utils/animation.h"
#include "utils/camera.h"
#include "inventory/inventory.h"

#include <SFML/Audio.h>

#define PLAYER_SPEED 100
#define CAMERA_SPEED 200
#define SOUND_COOLDOWN 0.25f
#define COOLDOWN 1.0f
#define COOLDOWN_PER_STRENGTH 0.1f
#define DEATH_COOLDOWN 2.0f

typedef enum {
    IDLE = 0,
    WALK,
    DEAD
} player_state_t;

typedef enum {
    LEFT = 0,
    RIGHT
} player_direction_t;

struct player {
    player_state_t state;
    player_direction_t direction;
    float death_cooldown;

    sfSprite *sprite;
    sfSprite *weapon;
    camera_t *camera;

    sfTexture *texture;
    sfTexture *weapon_texture;

    animation_t *idle_animation;
    animation_t *walk_animation;

    inventory_t *inventory;

    uint32_t level;
    uint32_t xp;
    uint8_t life;
    uint8_t max_life;
    uint8_t strength;
    float cooldown;

    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    float sound_cooldown;

    sfSound *hit_sound;
    sfSoundBuffer *hit_sound_buffer;

    sfSound *death_sound;
    sfSoundBuffer *death_sound_buffer;

    sfSound *lvlup_sound;
    sfSoundBuffer *lvlup_sound_buffer;

    sfSound *flask_sound;
    sfSoundBuffer *flask_sound_buffer;
};

bool player_on_attach(entity_t *entity);
void player_on_detach(entity_t *entity);
bool player_on_event(entity_t *entity, sfEvent *event);
bool player_on_update(entity_t *entity, float dt);
void player_on_render(entity_t *entity);

bool player_create_animations(entity_t *entity);
void player_update_camera(entity_t *entity, float dx, float dy, float dt);
void player_update_textures(entity_t *entity, float dt);

void player_update_movement(entity_t *entity, float dt);
void player_get_movement(entity_t *entity, float *dx, float *dy);
void player_update_state(entity_t *entity, float dx, float dy);
bool player_update_position(entity_t *entity, float dx, float dy, float dt);
void player_update_weapon_position(entity_t *entity);

float player_get_cooldown(entity_t *entity);
bool player_cast_spell(entity_t *entity, sfEvent *event);
bool player_create_sounds(player_t *player);
bool player_is_paused(entity_t *entity);
