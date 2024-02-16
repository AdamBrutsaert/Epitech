/*
** EPITECH PROJECT, 2022
** zombie_destroy.c
** File description:
** zombie_destroy.c
*/

#include "hunter.h"

void zombie_destroy(scene_t *scene)
{
    zombie_data_t *data = scene->data;
    zombie_args_t *args = scene->args;

    data->animation = args->side == LEFT
        ? ZOMBIE_FALLING_LEFT : ZOMBIE_FALLING_RIGHT;
    data->elapsed = 0.0f;
    data->frame = 0;
    sfSound_play(data->pop_sound);
}
