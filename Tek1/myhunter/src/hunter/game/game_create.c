/*
** EPITECH PROJECT, 2022
** game_create.c
** File description:
** game_create.c
*/

#include "hunter.h"

scene_t *game_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(game_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))game_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))game_on_detach);
    scene_bind(scene, "on_event", (void (*)(void))game_on_event);
    scene_bind(scene, "on_update", (void (*)(void))game_on_update);
    scene_bind(scene, "on_signal", (void (*)(void))game_on_signal);
    return scene;
}
