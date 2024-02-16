/*
** EPITECH PROJECT, 2022
** scene_create.c
** File description:
** scene_create.c
*/

#include "engine.h"
#include "my.h"

scene_t *scene_create(app_t *app, void *args, uint32_t data_size)
{
    scene_t *scene = my_malloc(sizeof(scene_t));

    scene->handlers.on_attach = NULL;
    scene->handlers.on_detach = NULL;
    scene->handlers.on_event = NULL;
    scene->handlers.on_signal = NULL;
    scene->handlers.on_update = NULL;
    scene->handlers.on_render = NULL;
    scene->children.scenes = NULL;
    scene->children.length = 0;
    scene->children.capacity = 0;
    scene->app = app;
    scene->args = args;
    scene->data = my_malloc(data_size);
    return scene;
}
