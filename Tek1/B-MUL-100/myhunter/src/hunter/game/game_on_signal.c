/*
** EPITECH PROJECT, 2022
** game_on_signal.c
** File description:
** game_on_signal.c
*/

#include "hunter.h"
#include "my.h"

static void on_game_over(scene_t *scene)
{
    game_over_args_t *args = my_malloc(sizeof(game_over_args_t));
    game_data_t *data = scene->data;

    args->score = ((score_data_t *)data->score->data)->score;
    args->lost = 1;
    app_set_scene(scene->app, game_over_create(scene->app, args));
}

static void on_win(scene_t *scene)
{
    game_over_args_t *args = my_malloc(sizeof(game_over_args_t));
    game_data_t *data = scene->data;

    args->score = ((score_data_t *)data->score->data)->score;
    args->lost = 0;
    app_set_scene(scene->app, game_over_create(scene->app, args));
}

void game_on_signal(scene_t *scene, __attribute__((unused)) scene_t *sender,
    char const *name)
{
    if (!my_strcmp(name, "wave_end")) {
        scene_send_signal(scene, "gain_heart");
        scene_send_signal(scene, "score_add_100");
    }
    if (!my_strcmp(name, "zombie_fell_out_of_map"))
        scene_send_signal(scene, "turn_hearts");
    if (!my_strcmp(name, "game_over"))
        on_game_over(scene);
    if (!my_strcmp(name, "win"))
        on_win(scene);
}
