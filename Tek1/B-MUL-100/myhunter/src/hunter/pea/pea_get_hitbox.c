/*
** EPITECH PROJECT, 2022
** pea_get_hitbox.c
** File description:
** pea_get_hitbox.c
*/

#include "hunter.h"

void pea_get_hitbox(scene_t *scene, sfFloatRect *rect)
{
    pea_data_t *data = scene->data;
    sfVector2f *pos = &((image_data_t *)data->image->data)->position;

    rect->left = pos->x + 3;
    rect->top = pos->y + 3;
    rect->width = 16 - 3;
    rect->height = 16 - 3;
}
