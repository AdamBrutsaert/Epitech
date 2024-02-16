/*
** EPITECH PROJECT, 2022
** image_set_texture_rect.c
** File description:
** image_set_texture_rect.c
*/

#include "hunter.h"
#include "my.h"

void image_set_texture_rect(scene_t *scene, sfIntRect *rect)
{
    image_data_t *data = scene->data;

    my_memcpy(&data->texture_rect, rect, sizeof(sfIntRect));
    image_update_vertices(scene);
}
