/*
** EPITECH PROJECT, 2022
** menu_on_event.c
** File description:
** menu_on_event.c
*/

#include "hunter.h"

void menu_on_event(scene_t *scene, sfEvent *event)
{
    if (event->type == sfEvtResized)
        menu_update_view(scene);
    if (event->type == sfEvtKeyPressed)
        app_set_scene(scene->app, game_create(scene->app));
}
