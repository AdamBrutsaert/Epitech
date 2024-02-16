/*
** EPITECH PROJECT, 2022
** scene_on_update.c
** File description:
** scene_on_update.c
*/

#include "engine.h"

void scene_on_update(scene_t *scene, float dt)
{
    if (scene->handlers.on_update)
        scene->handlers.on_update(scene, dt);
    for (uint32_t i = 0; i < scene->children.length; i++)
        scene_on_update(scene->children.scenes[i], dt);
}
