/*
** EPITECH PROJECT, 2022
** life_detach.c
** File description:
** life_detach.c
*/

#include "hunter.h"

void life_on_detach(scene_t *scene)
{
    life_data_t *data = scene->data;

    sfTexture_destroy(data->spritesheet);
}
