/*
** EPITECH PROJECT, 2022
** menu.h
** File description:
** menu.h
*/

#pragma once

#include "engine.h"

typedef struct {
    sfTexture *bg;
    sfSprite *sprite;
    sfMusic *music;
    sfFont *font;
    sfText *text;
    sfText *score;
    sfText *title;
} menu_data_t;

scene_t *menu_create(app_t *app);

void menu_on_attach(scene_t *scene);
void menu_on_detach(scene_t *scene);
void menu_on_event(scene_t *scene, sfEvent *event);
void menu_on_render(scene_t *scene);
void menu_update_view(scene_t *scene);
