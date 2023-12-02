/*
** EPITECH PROJECT, 2022
** image_create.c
** File description:
** image_create.c
*/

#include "hunter.h"

scene_t *image_create(app_t *app, image_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(image_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))image_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))image_on_detach);
    scene_bind(scene, "on_render", (void (*)(void))image_on_render);
    return scene;
}
