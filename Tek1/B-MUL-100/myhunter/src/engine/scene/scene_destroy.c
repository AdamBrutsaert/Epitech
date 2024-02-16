/*
** EPITECH PROJECT, 2022
** scene_destroy.c
** File description:
** scene_destroy.c
*/

#include "engine.h"
#include "my.h"

void scene_destroy(scene_t *scene)
{
    for (uint32_t i = 0; i < scene->children.length; i++) {
        scene_on_detach(scene->children.scenes[i]);
        scene_destroy(scene->children.scenes[i]);
    }
    my_free(scene->children.scenes);
    my_free(scene->args);
    my_free(scene->data);
    my_free(scene);
}
