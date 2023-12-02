/*
** EPITECH PROJECT, 2022
** zombie_on_detach.c
** File description:
** zombie_on_detach.c
*/

#include "hunter.h"

void zombie_on_detach(scene_t *scene)
{
    zombie_data_t *data = scene->data;

    sfSound_destroy(data->sound);
    sfSound_destroy(data->pop_sound);
}
