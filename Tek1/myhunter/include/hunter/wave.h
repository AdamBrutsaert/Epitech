/*
** EPITECH PROJECT, 2022
** wave.h
** File description:
** wave.h
*/

#pragma once

#include "engine.h"

typedef struct {
    scene_t **zombies;
    uint32_t length;
    uint32_t capacity;
} zombie_vector_t;

typedef struct {
    sfTexture *zombie_spritesheet;
    sfSoundBuffer *zombie_sound;
    sfSoundBuffer *zombie_pop_sound;
    sfSoundBuffer *awooga_sound;
    sfSound *sound;
    zombie_vector_t zombie_vector;
    uint32_t round;
    uint32_t alive;
    uint32_t to_spawn;
    float elapsed;
    float spawn_rate;
} wave_data_t;

scene_t *wave_create(app_t *app);

void wave_on_attach(scene_t *scene);
void wave_on_detach(scene_t *scene);
void wave_on_signal(scene_t *scene, scene_t *sender, char const *name);
void wave_on_update(scene_t *scene, float dt);

void wave_push_zombie(scene_t *scene);
void wave_pop_zombie(scene_t *scene, scene_t *zombie);
void wave_destroy_zombie(scene_t *scene, scene_t *zombie);
