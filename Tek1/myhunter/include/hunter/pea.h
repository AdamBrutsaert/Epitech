/*
** EPITECH PROJECT, 2022
** pea.h
** File description:
** pea.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *texture;
    sfVector2f direction;
    sfSoundBuffer *impact;
} pea_args_t;

typedef struct {
    scene_t *image;
    int8_t destroy;
    float elapsed;
    uint32_t frame;
    sfSound *sound;
} pea_data_t;

scene_t *pea_create(app_t *app, pea_args_t *args);

void pea_on_attach(scene_t *scene);
void pea_on_detach(scene_t *scene);
void pea_on_update(scene_t *scene, float dt);

void pea_destroy(scene_t *scene);
void pea_get_hitbox(scene_t *scene, sfFloatRect *rect);
