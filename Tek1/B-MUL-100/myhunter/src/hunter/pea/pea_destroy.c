/*
** EPITECH PROJECT, 2022
** pea_destroy.c
** File description:
** pea_destroy.c
*/

#include "hunter.h"

void pea_destroy(scene_t *scene)
{
    pea_data_t *data = scene->data;

    data->destroy = 1;
    sfSound_play(data->sound);
}
