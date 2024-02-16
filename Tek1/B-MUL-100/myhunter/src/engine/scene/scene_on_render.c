/*
** EPITECH PROJECT, 2022
** scene_on_render.c
** File description:
** scene_on_render.c
*/

#include "engine.h"

void scene_on_render(scene_t *scene)
{
    for (uint32_t i = 0; i < scene->children.length; i++)
        scene_on_render(scene->children.scenes[i]);
    if (scene->handlers.on_render)
        scene->handlers.on_render(scene);
}
