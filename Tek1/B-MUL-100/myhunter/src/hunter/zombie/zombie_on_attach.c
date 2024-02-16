/*
** EPITECH PROJECT, 2022
** zombie_on_attach.c
** File description:
** zombie_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void zombie_on_attach(scene_t *scene)
{
    zombie_data_t *data = scene->data;
    zombie_args_t *args = scene->args;
    image_args_t *img_args = my_malloc(sizeof(image_args_t));

    data->animation = args->side == LEFT
        ? ZOMBIE_MOVING_LEFT : ZOMBIE_MOVING_RIGHT;
    data->elapsed = 0.0f;
    data->frame = 0;
    img_args->position =
        (sfVector2f){args->side == LEFT ? -35 : 864,args->height};
    img_args->texture = args->spritesheet;
    img_args->texture_rect = (sfIntRect){0,args->side == LEFT ? 57 : 0,35,57};
    data->sound = sfSound_create();
    sfSound_setBuffer(data->sound, args->sound);
    data->pop_sound = sfSound_create();
    sfSound_setBuffer(data->pop_sound, args->pop_sound);
    data->image = scene_add_child(scene, image_create(scene->app, img_args));
    sfSound_play(data->sound);
}
