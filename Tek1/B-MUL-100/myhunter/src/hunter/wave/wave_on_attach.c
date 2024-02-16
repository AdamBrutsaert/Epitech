/*
** EPITECH PROJECT, 2022
** wave_on_attach.c
** File description:
** wave_on_attach.c
*/

#include "hunter.h"

void wave_on_attach(scene_t *scene)
{
    wave_data_t *data = scene->data;

    data->round = 0;
    data->alive = 0;
    data->to_spawn = 0;
    data->elapsed = 0.0f;
    data->spawn_rate = 0.0f;
    data->zombie_spritesheet = sfTexture_createFromFile("res/zombie.png", NULL);
    data->zombie_sound =
        sfSoundBuffer_createFromFile("res/loadingbar_zombie.ogg");
    data->zombie_pop_sound =
        sfSoundBuffer_createFromFile("res/balloon_pop.ogg");
    data->awooga_sound = sfSoundBuffer_createFromFile("res/awooga.ogg");
    data->sound = sfSound_create();
    sfSound_setBuffer(data->sound, data->awooga_sound);
    data->zombie_vector.capacity = 0;
    data->zombie_vector.length = 0;
    data->zombie_vector.zombies = NULL;
    sfSound_play(data->sound);
}
