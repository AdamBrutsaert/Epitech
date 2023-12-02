/*
** EPITECH PROJECT, 2022
** cursor_on_update.c
** File description:
** cursor_on_update.c
*/

#include "hunter.h"

void cursor_on_update(scene_t *scene, __attribute__((unused)) float dt)
{
    cursor_data_t *data = scene->data;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(scene->app->window);
    sfVector2f pos =
        sfRenderWindow_mapPixelToCoords(scene->app->window, mouse_pos, NULL);

    image_set_position(data->image, pos.x - 8, pos.y - 8);
}
