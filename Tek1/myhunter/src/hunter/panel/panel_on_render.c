/*
** EPITECH PROJECT, 2022
** panel_on_render.c
** File description:
** panel_on_render.c
*/

#include "hunter.h"

void panel_on_render(scene_t *scene)
{
    panel_data_t *data = scene->data;
    sfRenderWindow *window = scene->app->window;

    sfRenderWindow_drawSprite(window, data->sprite, NULL);
    sfRenderWindow_drawText(window, data->text, NULL);
    sfRenderWindow_drawText(window, data->score, NULL);
    sfRenderWindow_drawText(window, data->title, NULL);
}
