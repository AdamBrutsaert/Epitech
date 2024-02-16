/*
** EPITECH PROJECT, 2022
** wave_push_zombie.c
** File description:
** wave_push_zombie.c
*/

#include "hunter.h"
#include "my.h"
#include <stdlib.h>

static void realloc_vector(scene_t *scene)
{
    wave_data_t *data = scene->data;

    if (data->zombie_vector.capacity == data->zombie_vector.length) {
        data->zombie_vector.capacity *= 2;
        data->zombie_vector.capacity += !data->zombie_vector.capacity;
        data->zombie_vector.zombies = my_realloc(data->zombie_vector.zombies,
            sizeof(scene_t *) * data->zombie_vector.capacity);
    }
}

void wave_push_zombie(scene_t *scene)
{
    wave_data_t *data = scene->data;
    zombie_args_t *args = my_malloc(sizeof(zombie_args_t));
    uint32_t min_speed = 50 + data->round * 5;
    uint32_t max_speed = 75 + data->round * 10;

    min_speed = min_speed > 125 ? 125 : min_speed;
    max_speed = max_speed > 200 ? 200 : max_speed;
    args->spritesheet = data->zombie_spritesheet;
    args->height = rand() % 310;
    args->side = rand() % 2 ? LEFT : RIGHT;
    args->speed = min_speed + rand() % (max_speed - min_speed);
    args->sound = data->zombie_sound;
    args->pop_sound = data->zombie_pop_sound;
    realloc_vector(scene);
    data->zombie_vector.zombies[data->zombie_vector.length] =
        scene_add_child(scene, zombie_create(scene->app, args));
    data->zombie_vector.length++;
}
