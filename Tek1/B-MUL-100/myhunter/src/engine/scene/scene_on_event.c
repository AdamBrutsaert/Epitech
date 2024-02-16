/*
** EPITECH PROJECT, 2022
** scene_on_event.c
** File description:
** scene_on_event.c
*/

#include "engine.h"

void scene_on_event(scene_t *scene, sfEvent *event)
{
    if (scene->handlers.on_event)
        scene->handlers.on_event(scene, event);
    for (uint32_t i = 0; i < scene->children.length; i++)
        scene_on_event(scene->children.scenes[i], event);
}
