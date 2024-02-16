/*
** EPITECH PROJECT, 2022
** wave_on_signal.c
** File description:
** wave_on_signal.c
*/

#include "hunter.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

static void on_wave_start(scene_t *scene)
{
    wave_data_t *data = scene->data;

    data->round++;
    data->elapsed = 0.0f;
    data->alive = data->round / 2 + 5;
    data->spawn_rate = 2.5f / sqrt(data->round);
    if (data->alive > 25)
        data->alive = 25;
    if (data->spawn_rate < 0.75f)
        data->spawn_rate = 0.75f;
    data->to_spawn = data->alive;
}

static void on_zombie_killed(scene_t *scene)
{
    wave_data_t *data = scene->data;

    data->alive--;
    if (data->alive == 0)
        scene_send_signal(scene, "wave_end");
}

static void on_wave_end(scene_t *scene)
{
    wave_data_t *data = scene->data;

    data->to_spawn = 0;
    data->alive = 0;

    if (data->round == 30) {
        scene_send_signal(scene, "win");
    } else {
        sfSound_play(data->sound);
    }
}

void wave_on_signal(scene_t *scene, scene_t *sender, char const *name)
{
    wave_data_t *data = scene->data;

    if (!my_strcmp(name, "spawn_zombie")) {
        wave_push_zombie(scene);
        data->to_spawn--;
    }
    if (!my_strcmp(name, "zombie_out_of_map")) {
        wave_pop_zombie(scene, sender);
        scene_remove_child(scene, sender);
        scene_send_signal(scene, "lose_heart");
        on_zombie_killed(scene);
    }
    if (!my_strcmp(name, "zombie_fell_out_of_map")) {
        scene_remove_child(scene, sender);
        on_zombie_killed(scene);
    }
    if (!my_strcmp(name, "wave_start"))
        on_wave_start(scene);
    if (!my_strcmp(name, "wave_end"))
        on_wave_end(scene);
}
