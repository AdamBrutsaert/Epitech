/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** game.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *background_texture;
    sfMusic *music;
    scene_t *background;
    scene_t *life;
    scene_t *score;
    scene_t *peashooter;
    scene_t *wave;
    float elapsed;
} game_data_t;

scene_t *game_create(app_t *app);

int8_t game_test_resources(void);
void game_on_attach(scene_t *scene);
void game_on_detach(scene_t *scene);
void game_on_event(scene_t *scene, sfEvent *event);
void game_on_update(scene_t *scene, float dt);
void game_on_signal(scene_t *scene, scene_t *sender, char const *name);

void game_update_view(scene_t *scene);
