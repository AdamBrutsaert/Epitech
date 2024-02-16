/*
** EPITECH PROJECT, 2022
** game_on_attach.c
** File description:
** game_on_attach.c
*/

#include "hunter.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>

static void game_add_background(scene_t *scene)
{
    game_data_t *data = scene->data;
    image_args_t *args = my_malloc(sizeof(image_args_t));

    args->position.x = 0;
    args->position.y = 0;
    args->texture = data->background_texture;
    args->texture_rect.left = 0;
    args->texture_rect.top = 0;
    args->texture_rect.width = 864;
    args->texture_rect.height = 512;
    data->background = scene_add_child(scene, image_create(scene->app, args));
}

void game_on_attach(scene_t *scene)
{
    game_data_t *data = scene->data;

    srand(time(NULL));
    data->elapsed = 0.0f;
    data->background_texture = sfTexture_createFromFile("res/background.png",
        NULL);
    game_add_background(scene);
    game_update_view(scene);
    data->wave = scene_add_child(scene, wave_create(scene->app));
    data->peashooter = scene_add_child(scene, peashooter_create(scene->app));
    data->life = scene_add_child(scene, life_create(scene->app));
    data->score = scene_add_child(scene, score_create(scene->app));
    data->music = sfMusic_createFromFile("res/Loonboon.ogg");
    sfMusic_setLoop(data->music, sfTrue);
    sfMusic_play(data->music);
    scene_add_child(scene, cursor_create(scene->app));
}
