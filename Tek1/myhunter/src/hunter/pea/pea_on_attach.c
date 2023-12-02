/*
** EPITECH PROJECT, 2022
** pea_on_attach.c
** File description:
** pea_on_attach.c
*/

#include "hunter.h"
#include "my.h"
#include <math.h>

static void normalize_vector(sfVector2f *vector)
{
    float length = sqrt(vector->x * vector->x + vector->y * vector->y);

    if (length) {
        vector->x /= length;
        vector->y /= length;
    }
}

void pea_on_attach(scene_t *scene)
{
    pea_data_t *data = scene->data;
    pea_args_t *args = scene->args;
    image_args_t *img_args = my_malloc(sizeof(image_args_t));

    data->destroy = 0;
    data->elapsed = 0;
    data->frame = 0;
    data->sound = sfSound_create();
    sfSound_setBuffer(data->sound, args->impact);
    normalize_vector(&args->direction);
    img_args->position = (sfVector2f){410.0f, 480.0f};
    img_args->texture = args->texture;
    img_args->texture_rect = (sfIntRect){0, 0, 16, 16};
    data->image = scene_add_child(scene,
        image_create(scene->app, img_args));
}
