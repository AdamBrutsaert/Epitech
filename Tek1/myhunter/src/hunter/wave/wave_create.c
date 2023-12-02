/*
** EPITECH PROJECT, 2022
** wave_create.c
** File description:
** wave_create.c
*/

#include "hunter.h"

scene_t *wave_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(wave_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))wave_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))wave_on_detach);
    scene_bind(scene, "on_signal", (void (*)(void))wave_on_signal);
    scene_bind(scene, "on_update", (void (*)(void))wave_on_update);
    return scene;
}
