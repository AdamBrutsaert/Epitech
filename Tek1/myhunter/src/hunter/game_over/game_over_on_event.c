/*
** EPITECH PROJECT, 2022
** game_over_on_event.c
** File description:
** game_over_on_event.c
*/

#include "hunter.h"

void game_over_on_event(scene_t *scene, sfEvent *event)
{
    sfVector2i mouse_pos;
    sfVector2f pos;
    sfFloatRect hitbox = {366.0f, 376.0f, 134.0f, 24.0f};

    if (event->type == sfEvtResized)
        game_over_update_view(scene);
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        mouse_pos = (sfVector2i){event->mouseButton.x, event->mouseButton.y};
        pos = sfRenderWindow_mapPixelToCoords(scene->app->window, mouse_pos,
            NULL);
        if (sfFloatRect_contains(&hitbox, pos.x, pos.y))
            app_set_scene(scene->app, menu_create(scene->app));
    }
}
