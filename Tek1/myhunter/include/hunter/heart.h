/*
** EPITECH PROJECT, 2022
** heart.h
** File description:
** heart.h
*/

#pragma once

#include "engine.h"

#define HEART_TURN 0
#define HEART_SPAWN 1
#define HEART_DESTROY 2
#define HEART_RESPAWN 3

typedef struct {
    sfTexture *spritesheet;
    sfVector2f position;
} heart_args_t;

typedef struct {
    scene_t *image;
    int8_t ended;
    int8_t animation;
    float elapsed;
    uint8_t frame;
} heart_data_t;

scene_t *heart_create(app_t *app, heart_args_t *args);

void heart_on_attach(scene_t *scene);
void heart_on_update(scene_t *scene, float dt);

void heart_animate(scene_t *scene, int8_t animation);
