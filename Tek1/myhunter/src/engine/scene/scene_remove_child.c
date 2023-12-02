/*
** EPITECH PROJECT, 2022
** scene_remove_child.c
** File description:
** scene_remove_child.c
*/

#include "engine.h"
#include "my.h"

void scene_remove_child(scene_t *scene, scene_t *child)
{
    uint32_t i = 0;

    while (i < scene->children.length && scene->children.scenes[i] != child)
        i++;
    if (i != scene->children.length) {
        scene_on_detach(child);
        scene_destroy(child);
        my_memmove(&scene->children.scenes[i],
            &scene->children.scenes[i + 1],
            (scene->children.length - i - 1) * sizeof(scene_t *));
        scene->children.length--;
    }
}
