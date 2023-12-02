/*
** EPITECH PROJECT, 2022
** game_on_detach.c
** File description:
** game_on_detach.c
*/

#include "hunter.h"

void game_on_detach(scene_t *scene)
{
    game_data_t *data = scene->data;

    sfMusic_destroy(data->music);
    sfTexture_destroy(data->background_texture);
}
