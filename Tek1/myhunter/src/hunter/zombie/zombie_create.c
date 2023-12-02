/*
** EPITECH PROJECT, 2022
** zombie_create.c
** File description:
** zombie_create.c
*/

#include "hunter.h"

scene_t *zombie_create(app_t *app, zombie_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(zombie_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))zombie_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))zombie_on_detach);
    scene_bind(scene, "on_update", (void (*)(void))zombie_on_update);
    return scene;
}
