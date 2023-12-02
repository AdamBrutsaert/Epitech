/*
** EPITECH PROJECT, 2022
** cursor_create.c
** File description:
** cursor_create.c
*/

#include "hunter.h"

scene_t *cursor_create(app_t *app)
{
    scene_t *scene = scene_create(app, NULL, sizeof(cursor_data_t));

    scene_bind(scene, "on_attach", (void (*)(void))cursor_on_attach);
    scene_bind(scene, "on_detach", (void (*)(void))cursor_on_detach);
    scene_bind(scene, "on_update", (void (*)(void))cursor_on_update);
    return (scene);
}
