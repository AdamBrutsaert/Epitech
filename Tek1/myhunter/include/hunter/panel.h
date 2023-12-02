/*
** EPITECH PROJECT, 2022
** panel.h
** File description:
** panel.h
*/

#pragma once

#include "engine.h"

typedef struct {
    uint64_t score;
    int8_t lost;
} panel_args_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfText *title;
    sfText *score;
} panel_data_t;

scene_t *panel_create(app_t *app, panel_args_t *args);

void panel_on_attach(scene_t *scene);
void panel_on_detach(scene_t *scene);
void panel_on_render(scene_t *scene);
