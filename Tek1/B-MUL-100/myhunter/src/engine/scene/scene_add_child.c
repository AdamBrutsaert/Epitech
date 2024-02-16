/*
** EPITECH PROJECT, 2022
** scene_add_child.c
** File description:
** scene_add_child.c
*/

#include "engine.h"
#include "my.h"

scene_t *scene_add_child(scene_t *scene, scene_t *child)
{
    if (scene->children.length == scene->children.capacity) {
        scene->children.capacity *= 2;
        scene->children.capacity += !scene->children.capacity;
        scene->children.scenes = my_realloc(scene->children.scenes,
            scene->children.capacity * sizeof(scene_t *));
    }
    scene->children.scenes[scene->children.length] = child;
    scene_on_attach(child);
    scene->children.length++;
    return child;
}
