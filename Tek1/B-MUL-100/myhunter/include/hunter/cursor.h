/*
** EPITECH PROJECT, 2022
** cursor.h
** File description:
** cursor.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *texture;
    scene_t *image;
} cursor_data_t;

scene_t *cursor_create(app_t *app);

void cursor_on_attach(scene_t *scene);
void cursor_on_detach(scene_t *scene);
void cursor_on_update(scene_t *scene, float dt);
