/*
** EPITECH PROJECT, 2022
** heart_on_attach.c
** File description:
** heart_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void heart_on_attach(scene_t *scene)
{
    heart_data_t *data = scene->data;
    heart_args_t *args = scene->args;
    image_args_t *img_args = my_malloc(sizeof(image_args_t));

    img_args->position = args->position;
    img_args->texture = args->spritesheet;
    img_args->texture_rect = (sfIntRect){0,144,48,48};
    data->ended = 0;
    data->elapsed = 0.0f;
    data->frame = 0;
    data->animation = HEART_SPAWN;
    data->image = scene_add_child(scene, image_create(scene->app, img_args));
}
