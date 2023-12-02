/*
** EPITECH PROJECT, 2022
** cursor_on_attach.c
** File description:
** cursor_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void cursor_on_attach(scene_t *scene)
{
    cursor_data_t *data = scene->data;
    image_args_t *args = my_malloc(sizeof(image_args_t));

    sfRenderWindow_setMouseCursorVisible(scene->app->window, sfFalse);
    data->texture = sfTexture_createFromFile("res/cursor.png", NULL);
    args->position = (sfVector2f){0.0f, 0.0f};
    args->texture = data->texture;
    args->texture_rect = (sfIntRect){0.0f,0.0f,15.0f,15.0f};
    data->image = scene_add_child(scene, image_create(scene->app, args));
}
