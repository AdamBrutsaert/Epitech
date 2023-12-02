/*
** EPITECH PROJECT, 2022
** wave_on_detach.c
** File description:
** wave_on_detach.c
*/

#include "hunter.h"
#include "my.h"

void wave_on_detach(scene_t *scene)
{
    wave_data_t *data = scene->data;

    my_free(data->zombie_vector.zombies);
    sfSound_destroy(data->sound);
    sfSoundBuffer_destroy(data->awooga_sound);
    sfSoundBuffer_destroy(data->zombie_sound);
    sfSoundBuffer_destroy(data->zombie_pop_sound);
    sfTexture_destroy(data->zombie_spritesheet);
}
