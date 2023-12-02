/*
** EPITECH PROJECT, 2022
** life_create.c
** File description:
** life_create.c
*/

#include "hunter.h"

scene_t *life_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(life_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))life_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))life_on_detach);
    scene_bind(scene, "on_signal", (void (*)(void))life_on_signal);
    return scene;
}
