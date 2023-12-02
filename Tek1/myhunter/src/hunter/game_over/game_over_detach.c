/*
** EPITECH PROJECT, 2022
** game_over_detach.c
** File description:
** game_over_detach.c
*/

#include "hunter.h"

void game_over_on_detach(scene_t *scene)
{
    game_over_data_t *data = scene->data;

    sfMusic_destroy(data->music);
}
