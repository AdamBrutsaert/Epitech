/*
** EPITECH PROJECT, 2022
** game_over_create.c
** File description:
** game_over_create.c
*/

#include "hunter.h"

scene_t *game_over_create(app_t *app, game_over_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(game_over_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))game_over_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))game_over_on_detach);
    scene_bind(scene, "on_event", (void (*)(void))game_over_on_event);
    return scene;
}
