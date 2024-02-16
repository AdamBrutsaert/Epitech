/*
** EPITECH PROJECT, 2022
** panel_create.c
** File description:
** panel_create.c
*/

#include "hunter.h"

scene_t *panel_create(app_t *app, panel_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(panel_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))panel_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))panel_on_detach);
    scene_bind(scene, "on_render", (void (*)(void))panel_on_render);
    return scene;
}
