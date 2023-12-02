/*
** EPITECH PROJECT, 2022
** peashooter_create.c
** File description:
** peashooter_create.c
*/

#include "hunter.h"

scene_t *peashooter_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(peashooter_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))peashooter_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))peashooter_on_detach);
    scene_bind(scene, "on_event", (void (*)(void))peashooter_on_event);
    scene_bind(scene, "on_signal", (void (*)(void))peashooter_on_signal);
    scene_bind(scene, "on_render", (void (*)(void))peashooter_on_render);
    return scene;
}
