/*
** EPITECH PROJECT, 2022
** score_on_attach.c
** File description:
** score_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void score_on_attach(scene_t *scene)
{
    score_data_t *data = scene->data;
    image_args_t *args = my_malloc(sizeof(image_args_t));

    data->score = 0;
    data->to_add = 0;
    data->elapsed = 0.0f;
    data->box_texture = sfTexture_createFromFile("res/box.png", NULL);
    data->digits_texture = sfTexture_createFromFile("res/digits.png", NULL);
    args->position = (sfVector2f){714,470};
    args->texture = data->box_texture;
    args->texture_rect = (sfIntRect){0,0,144,36};
    data->box = scene_add_child(scene, image_create(scene->app, args));
    for (uint32_t i = 0; i < 9; i++)
        data->digits[i] = NULL;
    score_update_digits(scene);
}
