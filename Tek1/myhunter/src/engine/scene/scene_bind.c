/*
** EPITECH PROJECT, 2022
** scene_bind.c
** File description:
** scene_bind.c
*/

#include "engine.h"
#include "my.h"

void scene_bind(scene_t *scene, char const *name, void (*func)(void))
{
    if (!my_strcmp(name, "on_attach"))
        scene->handlers.on_attach = (void (*)(scene_t *))func;
    if (!my_strcmp(name, "on_detach"))
        scene->handlers.on_detach = (void (*)(scene_t *))func;
    if (!my_strcmp(name, "on_event"))
        scene->handlers.on_event = (void (*)(scene_t *, sfEvent *))func;
    if (!my_strcmp(name, "on_signal"))
        scene->handlers.on_signal = (void (*)(scene_t *, scene_t *,
            char const *))func;
    if (!my_strcmp(name, "on_update"))
        scene->handlers.on_update = (void (*)(scene_t *, float))func;
    if (!my_strcmp(name, "on_render"))
        scene->handlers.on_render = (void (*)(scene_t *))func;
}
