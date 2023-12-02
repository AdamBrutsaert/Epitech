/*
** EPITECH PROJECT, 2022
** game_on_event.c
** File description:
** game_on_event.c
*/

#include "hunter.h"

static void game_kill_zombies(scene_t *scene)
{
    wave_data_t *data = ((game_data_t *)scene->data)->wave->data;

    for (uint32_t i = data->zombie_vector.length; i; i--)
        wave_destroy_zombie(((game_data_t *)scene->data)->wave,
            data->zombie_vector.zombies[i - 1]);
}

static void game_kill_peas(scene_t *scene)
{
    peashooter_data_t *data = ((game_data_t *)scene->data)->peashooter->data;

    for (uint32_t i = data->pea_vector.length; i; i--)
        peashooter_destroy_pea(((game_data_t *)scene->data)->peashooter,
            data->pea_vector.peas[i - 1]);
}

static void game_end_wave(scene_t *scene)
{
    game_kill_zombies(scene);
    game_kill_peas(scene);
    scene_send_signal(scene, "wave_end");
    scene_send_signal(scene, "wave_start");
}

static void game_handle_cheats(scene_t *scene, sfEvent *event)
{
    if (event->key.code == sfKeyNumpad0)
        scene_send_signal(scene, "turn_hearts");
    if (event->key.code == sfKeyNumpad1)
        scene_send_signal(scene, "lose_heart");
    if (event->key.code == sfKeyNumpad2)
        scene_send_signal(scene, "gain_heart");
    if (event->key.code == sfKeyNumpad3)
        scene_send_signal(scene, "regain_hearts");
    if (event->key.code == sfKeyNumpad4)
        game_end_wave(scene);
    if (event->key.code == sfKeyNumpad5)
        game_kill_zombies(scene);
    if (event->key.code == sfKeyNumpad6)
        game_kill_peas(scene);
    if (event->key.code == sfKeyNumpad7)
        scene_send_signal(scene, "score_add_1");
    if (event->key.code == sfKeyNumpad8)
        scene_send_signal(scene, "score_add_10");
    if (event->key.code == sfKeyNumpad9)
        scene_send_signal(scene, "score_add_100");
}

void game_on_event(scene_t *scene, sfEvent *event)
{
    if (event->type == sfEvtResized)
        game_update_view(scene);
    if (event->type == sfEvtKeyPressed)
        game_handle_cheats(scene, event);
}
