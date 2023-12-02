/*
** EPITECH PROJECT, 2022
** menu_on_detach.c
** File description:
** menu_on_detach.c
*/

#include "hunter.h"

void menu_on_detach(scene_t *scene)
{
    menu_data_t *data = scene->data;

    sfFont_destroy(data->font);
    sfText_destroy(data->text);
    sfText_destroy(data->score);
    sfText_destroy(data->title);
    sfTexture_destroy(data->bg);
    sfSprite_destroy(data->sprite);
    sfMusic_destroy(data->music);
}
