/*
** EPITECH PROJECT, 2022
** score_on_detach.c
** File description:
** score_on_detach.c
*/

#include "hunter.h"

void score_on_detach(scene_t *scene)
{
    score_data_t *data = scene->data;

    sfTexture_destroy(data->box_texture);
    sfTexture_destroy(data->digits_texture);
}
