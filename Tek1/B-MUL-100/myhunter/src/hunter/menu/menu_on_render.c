/*
** EPITECH PROJECT, 2022
** menu_on_render.c
** File description:
** menu_on_render.c
*/

#include "hunter.h"

void menu_on_render(scene_t *scene)
{
    menu_data_t *data = scene->data;
    sfRenderWindow *window = scene->app->window;

    sfRenderWindow_drawSprite(window, data->sprite, NULL);
    sfRenderWindow_drawText(window, data->text, NULL);
    sfRenderWindow_drawText(window, data->score, NULL);
    sfRenderWindow_drawText(window, data->title, NULL);
}
