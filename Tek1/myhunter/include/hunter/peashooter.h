/*
** EPITECH PROJECT, 2022
** peashooter.h
** File description:
** peashooter.h
*/

#pragma once

#include "engine.h"

typedef struct {
    scene_t **peas;
    uint32_t capacity;
    uint32_t length;
} pea_vector_t;

typedef struct {
    sfTexture *pea_texture;
    sfTexture *peashooter_texture;
    sfSprite *peashooter;
    pea_vector_t pea_vector;
    sfSoundBuffer *floop;
    sfSoundBuffer *impact;
    sfSound *sound;
} peashooter_data_t;

scene_t *peashooter_create(app_t *app);

void peashooter_on_attach(scene_t *scene);
void peashooter_on_detach(scene_t *scene);
void peashooter_on_event(scene_t *scene, sfEvent *event);
void peashooter_on_signal(scene_t *scene, scene_t *sender, char const *name);
void peashooter_on_render(scene_t *scene);

void peashooter_pop_pea(scene_t *scene, scene_t *pea);
void peashooter_destroy_pea(scene_t *scene, scene_t *pea);
