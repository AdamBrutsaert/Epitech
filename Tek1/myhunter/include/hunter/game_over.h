/*
** EPITECH PROJECT, 2022
** game_over.h
** File description:
** game_over.h
*/

#pragma once

#include "engine.h"

typedef struct {
    uint64_t score;
    int8_t lost;
} game_over_args_t;

typedef struct {
    sfTexture *bg;
    sfMusic *music;
} game_over_data_t;

scene_t *game_over_create(app_t *app, game_over_args_t *args);

void game_over_on_attach(scene_t *scene);
void game_over_on_detach(scene_t *scene);
void game_over_on_event(scene_t *scene, sfEvent *event);
void game_over_update_view(scene_t *scene);
