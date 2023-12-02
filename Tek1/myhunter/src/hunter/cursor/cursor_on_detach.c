/*
** EPITECH PROJECT, 2022
** cursor_on_detach.c
** File description:
** cursor_on_detach.c
*/

#include "hunter.h"

void cursor_on_detach(scene_t *scene)
{
    cursor_data_t *data = scene->data;

    sfTexture_destroy(data->texture);
    sfRenderWindow_setMouseCursorVisible(scene->app->window, sfTrue);
}
