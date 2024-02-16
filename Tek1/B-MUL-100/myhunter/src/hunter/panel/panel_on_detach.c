/*
** EPITECH PROJECT, 2022
** panel_on_detach.c
** File description:
** panel_on_detach.c
*/

#include "hunter.h"

void panel_on_detach(scene_t *scene)
{
    panel_data_t *data = scene->data;

    sfFont_destroy(data->font);
    sfText_destroy(data->text);
    sfText_destroy(data->title);
    sfText_destroy(data->score);
    sfTexture_destroy(data->texture);
    sfSprite_destroy(data->sprite);
}
