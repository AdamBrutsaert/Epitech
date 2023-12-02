/*
** EPITECH PROJECT, 2022
** image_set_position.c
** File description:
** image_set_position.c
*/

#include "hunter.h"

void image_set_position(scene_t *scene, float x, float y)
{
    ((image_data_t*)scene->data)->position.x = x;
    ((image_data_t*)scene->data)->position.y = y;
    image_update_vertices(scene);
}
