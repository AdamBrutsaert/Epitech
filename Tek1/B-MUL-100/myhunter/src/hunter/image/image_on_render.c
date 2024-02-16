/*
** EPITECH PROJECT, 2022
** image_on_render.c
** File description:
** image_on_render.c
*/

#include "hunter.h"

void image_on_render(scene_t *scene)
{
    image_data_t *data = scene->data;

    sfRenderWindow_drawVertexArray(scene->app->window, data->vertices,
        &data->states);
}
