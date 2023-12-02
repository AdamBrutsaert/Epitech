/*
** EPITECH PROJECT, 2022
** game_over_on_attach.c
** File description:
** game_over_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void game_over_on_attach(scene_t *scene)
{
    game_over_data_t *data = scene->data;
    game_over_args_t *args = scene->args;
    image_args_t *img_args = my_malloc(sizeof(image_args_t));
    panel_args_t *panel_args = my_malloc(sizeof(panel_args_t));

    if (args->score >= read_best_score())
        write_best_score(args->score);
    data->bg = sfTexture_createFromFile("res/background.png", NULL);
    data->music = sfMusic_createFromFile("res/Moongrains.ogg");
    sfMusic_play(data->music);
    sfMusic_setLoop(data->music, sfTrue);
    img_args->texture = data->bg;
    img_args->texture_rect = (sfIntRect){0.0f, 0.0f, 864.0f, 512.0f};
    img_args->position = (sfVector2f){0.0f, 0.0f};
    scene_add_child(scene, image_create(scene->app, img_args));
    panel_args->score = args->score;
    panel_args->lost = args->lost;
    scene_add_child(scene, panel_create(scene->app, panel_args));
    game_over_update_view(scene);
}
