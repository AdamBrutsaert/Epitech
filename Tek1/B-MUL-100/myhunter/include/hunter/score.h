/*
** EPITECH PROJECT, 2022
** score.h
** File description:
** score.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *box_texture;
    sfTexture *digits_texture;
    scene_t *box;
    scene_t *digits[9];
    uint32_t score;
    uint32_t to_add;
    float elapsed;
} score_data_t;

scene_t *score_create(app_t *app);

void score_on_attach(scene_t *scene);
void score_on_detach(scene_t *scene);
void score_on_signal(scene_t *scene, scene_t *sender, char const *name);
void score_on_update(scene_t *scene, float dt);

void score_update_digits(scene_t *scene);
