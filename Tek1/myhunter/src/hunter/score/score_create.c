/*
** EPITECH PROJECT, 2022
** score_create.c
** File description:
** score_create.c
*/

#include "hunter.h"

scene_t *score_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(score_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))score_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))score_on_detach);
    scene_bind(scene, "on_signal", (void (*)(void))score_on_signal);
    scene_bind(scene, "on_update", (void (*)(void))score_on_update);
    return scene;
}
