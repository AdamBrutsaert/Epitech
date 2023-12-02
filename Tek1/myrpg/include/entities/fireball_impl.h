/*
** EPITECH PROJECT, 2023
** fireball_impl.h
** File description:
** fireball_impl.h
*/

#pragma once

#include "fireball.h"
#include "utils/animation.h"

#include <SFML/Audio.h>

#define FIREBALL_SPEED 200

typedef struct {
    entity_t *player;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f movement;
    animation_t *animation;
    animation_t *destroying;
    bool is_destroyed;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    sfSound *boom;
    sfSoundBuffer *boom_buffer;
} entity_fireball_t;

bool entity_fireball_on_attach(entity_t *entity);
void entity_fireball_on_detach(entity_t *entity);
bool entity_fireball_on_event(entity_t *entity, sfEvent *event);
bool entity_fireball_on_update(entity_t *entity, float dt);
void entity_fireball_on_render(entity_t *entity);
