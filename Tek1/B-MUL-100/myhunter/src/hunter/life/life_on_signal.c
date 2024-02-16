/*
** EPITECH PROJECT, 2022
** life_on_signal.c
** File description:
** life_on_signal.c
*/

#include "hunter.h"
#include "my.h"

static void life_gain_heart(scene_t *scene)
{
    life_data_t *data = scene->data;
    heart_args_t *args;

    if (data->life >= 3)
        return;
    args = my_malloc(sizeof(heart_args_t));
    args->spritesheet = data->spritesheet;
    args->position = (sfVector2f){data->life * 48, 464};
    data->hearts[data->life] =
        scene_add_child(scene, heart_create(scene->app, args));
    heart_animate(data->hearts[data->life], HEART_RESPAWN);
    data->life++;
}

static void life_lose_heart(scene_t *scene)
{
    life_data_t *data = scene->data;

    heart_animate(data->hearts[data->life - 1], HEART_DESTROY);
    data->life--;
    if (data->life == 0)
        scene_send_signal(scene, "game_over");
}

static void life_turn_hearts(scene_t *scene)
{
    life_data_t *data = scene->data;

    for (uint8_t i = 0; i < data->life; i++)
        heart_animate(data->hearts[i], HEART_TURN);
}

static void life_regain_hearts(scene_t *scene)
{
    life_data_t *data = scene->data;

    for (uint8_t i = 0; i < data->life; i++)
        heart_animate(data->hearts[i], HEART_SPAWN);
    for (uint8_t i = data->life; i < 3; i++) {
        life_gain_heart(scene);
        heart_animate(data->hearts[i], HEART_SPAWN);
    }
}

void life_on_signal(scene_t *scene, scene_t *sender, char const *name)
{
    if (!my_strcmp(name, "turn_hearts"))
        life_turn_hearts(scene);
    if (!my_strcmp(name, "gain_heart"))
        life_gain_heart(scene);
    if (!my_strcmp(name, "regain_hearts"))
        life_regain_hearts(scene);
    if (!my_strcmp(name, "lose_heart"))
        life_lose_heart(scene);
    if (!my_strcmp(name, "heart_animation_destroy_finished"))
        scene_remove_child(scene, sender);
}
