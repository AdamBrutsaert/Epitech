/*
** EPITECH PROJECT, 2022
** image_on_adetach.c
** File description:
** image_on_detach.c
*/

#include "hunter.h"

void image_on_detach(scene_t *scene)
{
    image_data_t *data = scene->data;

    sfVertexArray_destroy(data->vertices);
}
