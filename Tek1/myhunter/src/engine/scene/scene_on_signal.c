/*
** EPITECH PROJECT, 2022
** scene_on_signal.c
** File description:
** scene_on_signal.c
*/

#include "engine.h"

void scene_on_signal(scene_t *scene, scene_t *sender, char const *name)
{
    if (scene->handlers.on_signal)
        scene->handlers.on_signal(scene, sender, name);
    for (uint32_t i = 0; i < scene->children.length; i++)
        scene_on_signal(scene->children.scenes[i], sender, name);
}
