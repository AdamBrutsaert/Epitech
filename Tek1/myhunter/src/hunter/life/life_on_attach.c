/*
** EPITECH PROJECT, 2022
** life_on_attach.c
** File description:
** life_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void life_on_attach(scene_t *scene)
{
    life_data_t *data = scene->data;
    heart_args_t *args;

    data->spritesheet = sfTexture_createFromFile("res/heart.png", NULL);
    data->life = 3;
    for (uint8_t i = 0; i < 3; i++) {
        args = my_malloc(sizeof(heart_args_t));
        args->spritesheet = data->spritesheet;
        args->position = (sfVector2f){i * 48, 464};
        data->hearts[i] = scene_add_child(scene,
            heart_create(scene->app, args));
    }
}
