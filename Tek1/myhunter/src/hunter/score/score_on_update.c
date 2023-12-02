/*
** EPITECH PROJECT, 2022
** score_on_update.c
** File description:
** score_on_update.c
*/

#include "hunter.h"

void score_on_update(scene_t *scene, float dt)
{
    score_data_t *data = scene->data;

    if (!data->to_add) {
        data->elapsed = 0.0f;
        return;
    }
    data->elapsed += dt;
    if (data->elapsed >= 0.01f) {
        data->score += 1;
        data->to_add -= 1;
        data->elapsed -= 0.01f;
        score_update_digits(scene);
    }
}
