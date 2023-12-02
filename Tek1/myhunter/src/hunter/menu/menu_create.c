/*
** EPITECH PROJECT, 2022
** menu_create.c
** File description:
** menu_create.c
*/

#include "hunter.h"

scene_t *menu_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(menu_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))menu_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))menu_on_detach);
    scene_bind(scene, "on_event", (void (*)(void))menu_on_event);
    scene_bind(scene, "on_render", (void (*)(void))menu_on_render);
    return scene;
}
