/*
** EPITECH PROJECT, 2022
** wave_on_update.c
** File description:
** wave_on_update.c
*/

#include "hunter.h"

void wave_on_update(scene_t *scene, float dt)
{
    wave_data_t *data = scene->data;

    if (data->to_spawn || (!data->alive && !data->to_spawn))
        data->elapsed += dt;
    if (data->to_spawn && data->elapsed >= data->spawn_rate) {
        scene_send_signal(scene, "spawn_zombie");
        data->elapsed -= data->spawn_rate;
    }
    if (!data->alive && data->elapsed >= 2.5f)
        scene_send_signal(scene, "wave_start");
}
