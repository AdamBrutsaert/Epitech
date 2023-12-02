/*
** EPITECH PROJECT, 2022
** app_set_scene.c
** File description:
** app_set_scene.c
*/

#include "engine.h"

void app_set_scene(app_t *app, scene_t *scene)
{
    app->next_scene = scene;
}
