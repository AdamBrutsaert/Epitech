/*
** EPITECH PROJECT, 2022
** life.h
** File description:
** life.h
*/

#pragma once

#include "heart.h"

typedef struct {
    sfTexture *spritesheet;
    scene_t *hearts[3];
    uint8_t life;
} life_data_t;

scene_t *life_create(app_t *app);

void life_on_attach(scene_t *scene);
void life_on_detach(scene_t *scene);
void life_on_signal(scene_t *scene, scene_t *sender, char const *name);
