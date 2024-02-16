/*
** EPITECH PROJECT, 2022
** zombie.h
** File description:
** zombie.h
*/

#pragma once

#include "engine.h"

#define ZOMBIE_MOVING_LEFT 0
#define ZOMBIE_MOVING_RIGHT 1
#define ZOMBIE_FALLING_LEFT 2
#define ZOMBIE_FALLING_RIGHT 3

typedef struct {
    sfSoundBuffer *sound;
    sfSoundBuffer *pop_sound;
    sfTexture *spritesheet;
    enum { LEFT, RIGHT } side;
    uint32_t height;
    float speed;
} zombie_args_t;

typedef struct {
    sfSound *sound;
    sfSound *pop_sound;
    scene_t *image;
    int8_t animation;
    float elapsed;
    uint8_t frame;
} zombie_data_t;

scene_t *zombie_create(app_t *app, zombie_args_t *args);

void zombie_on_attach(scene_t *scene);
void zombie_on_detach(scene_t *scene);
void zombie_on_update(scene_t *scene, float dt);

void zombie_destroy(scene_t *scene);
void zombie_get_hitbox(scene_t *scene, sfFloatRect *hitbox);
