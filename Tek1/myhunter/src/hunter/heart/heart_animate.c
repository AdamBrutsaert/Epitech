/*
** EPITECH PROJECT, 2022
** heart_animate.c
** File description:
** heart_animate.c
*/

#include "hunter.h"

void heart_animate(scene_t *scene, int8_t animation)
{
    heart_data_t *data = scene->data;

    data->animation = animation;
    data->ended = 0;
    data->frame = 0;
    data->elapsed = 0.0f;
}
