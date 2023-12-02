/*
** EPITECH PROJECT, 2022
** peashooter_on_detach.c
** File description:
** peashooter_on_detach.c
*/

#include "hunter.h"
#include "my.h"

void peashooter_on_detach(scene_t *scene)
{
    peashooter_data_t *data = scene->data;

    sfSoundBuffer_destroy(data->floop);
    sfSoundBuffer_destroy(data->impact);
    sfSound_destroy(data->sound);
    sfTexture_destroy(data->pea_texture);
    my_free(data->pea_vector.peas);
}
