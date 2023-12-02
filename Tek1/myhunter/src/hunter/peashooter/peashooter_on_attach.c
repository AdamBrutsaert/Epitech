/*
** EPITECH PROJECT, 2022
** peashooter_on_attach.c
** File description:
** peashooter_on_attach.c
*/

#include "hunter.h"

void peashooter_on_attach(scene_t *scene)
{
    peashooter_data_t *data = scene->data;

    data->pea_texture = sfTexture_createFromFile("res/pea.png", NULL);
    data->pea_vector.peas = NULL;
    data->pea_vector.capacity = 0;
    data->pea_vector.length = 0;
    data->floop = sfSoundBuffer_createFromFile("res/floop.ogg");
    data->impact = sfSoundBuffer_createFromFile("res/melonimpact.ogg");
    data->sound = sfSound_create();
    data->peashooter_texture = sfTexture_createFromFile("res/peashooter.png",
        NULL);
    data->peashooter = sfSprite_create();
    sfSprite_setTexture(data->peashooter, data->peashooter_texture, sfTrue);
    sfSprite_setPosition(data->peashooter, (sfVector2f){384.0f, 448.0f});
    sfSound_setBuffer(data->sound, data->floop);
}
