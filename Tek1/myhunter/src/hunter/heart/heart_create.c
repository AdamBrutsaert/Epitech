/*
** EPITECH PROJECT, 2022
** heart_create.c
** File description:
** heart_create.c
*/

#include "hunter.h"

scene_t *heart_create(app_t *app, heart_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(heart_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))heart_on_attach);
    scene_bind(scene, "on_update", (void (*)(void))heart_on_update);
    return scene;
}
