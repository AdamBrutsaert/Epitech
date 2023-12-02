/*
** EPITECH PROJECT, 2022
** scene_on_attach.c
** File description:
** scene_on_attach.c
*/

#include "engine.h"

void scene_on_attach(scene_t *scene)
{
    if (scene->handlers.on_attach)
        scene->handlers.on_attach(scene);
}
