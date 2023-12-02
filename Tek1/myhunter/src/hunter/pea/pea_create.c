/*
** EPITECH PROJECT, 2022
** pea_create.c
** File description:
** pea_create.c
*/

#include "hunter.h"

scene_t *pea_create(app_t *app, pea_args_t *args)
{
    scene_t *scene = scene_create(app, args, sizeof(pea_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))pea_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))pea_on_detach);
    scene_bind(scene, "on_update", (void (*)(void))pea_on_update);
    return scene;
}
