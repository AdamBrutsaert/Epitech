/*
** EPITECH PROJECT, 2022
** image.h
** File description:
** image.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *texture;
    sfIntRect texture_rect;
    sfVector2f position;
} image_args_t;

typedef struct {
    sfVertexArray *vertices;
    sfRenderStates states;
    sfIntRect texture_rect;
    sfVector2f position;
} image_data_t;

scene_t *image_create(app_t *app, image_args_t *args);

void image_on_attach(scene_t *scene);
void image_on_detach(scene_t *scene);
void image_on_render(scene_t *scene);

void image_set_position(scene_t *scene, float x, float y);
void image_set_texture_rect(scene_t *scene, sfIntRect *rect);
void image_update_vertices(scene_t *scene);
