/*
** EPITECH PROJECT, 2022
** pea_on_detach.c
** File description:
** pea_on_detach.c
*/

#include "hunter.h"

void pea_on_detach(scene_t *scene)
{
    pea_data_t *data = scene->data;

    sfSound_destroy(data->sound);
}
