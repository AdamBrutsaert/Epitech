/*
** EPITECH PROJECT, 2022
** scene_on_detach.c
** File description:
** scene_on_detach.c
*/

#include "engine.h"

void scene_on_detach(scene_t *scene)
{
    if (scene->handlers.on_detach)
        scene->handlers.on_detach(scene);
}
