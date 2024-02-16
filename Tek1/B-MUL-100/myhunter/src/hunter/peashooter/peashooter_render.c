/*
** EPITECH PROJECT, 2022
** peashooter_render.c
** File description:
** peashooter_render.c
*/

#include "hunter.h"

void peashooter_on_render(scene_t *scene)
{
    peashooter_data_t *data = scene->data;
    sfRenderWindow *window = scene->app->window;

    sfRenderWindow_drawSprite(window, data->peashooter, NULL);
}
