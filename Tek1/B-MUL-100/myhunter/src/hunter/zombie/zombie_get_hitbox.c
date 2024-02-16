/*
** EPITECH PROJECT, 2022
** zombie_get_hitbox.c
** File description:
** zombie_get_hitbox.c
*/

#include "hunter.h"

void zombie_get_hitbox(scene_t *scene, sfFloatRect *hitbox)
{
    zombie_data_t *data = scene->data;
    sfVector2f *pos = &((image_data_t*)data->image->data)->position;

    hitbox->left = pos->x + 4;
    hitbox->top = pos->y + 6;
    hitbox->width = 35 - 4;
    hitbox->height = 57 - 20;
}
