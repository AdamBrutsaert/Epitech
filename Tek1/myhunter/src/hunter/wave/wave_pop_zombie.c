/*
** EPITECH PROJECT, 2022
** wave_pop_zombie.c
** File description:
** wave_pop_zombie.c
*/

#include "hunter.h"
#include "my.h"

void wave_pop_zombie(scene_t *scene, scene_t *zombie)
{
    wave_data_t *data = scene->data;
    uint32_t i = 0;

    while (i < data->zombie_vector.length
        && data->zombie_vector.zombies[i] != zombie)
        i++;
    if (i == data->zombie_vector.length)
        return;
    my_memmove(&data->zombie_vector.zombies[i],
        &data->zombie_vector.zombies[i + 1],
        sizeof(scene_t *) * (data->zombie_vector.length - i - 1));
    data->zombie_vector.length--;
}
