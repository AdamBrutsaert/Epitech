/*
** EPITECH PROJECT, 2022
** score_on_signal.c
** File description:
** score_on_signal.c
*/

#include "hunter.h"
#include "my.h"

void score_on_signal(scene_t *scene, __attribute__((unused)) scene_t *sender,
    char const *name)
{
    score_data_t *data = scene->data;

    if (!my_strcmp(name, "score_add_1"))
        data->to_add += 1;
    if (!my_strcmp(name, "score_add_10"))
        data->to_add += 10;
    if (!my_strcmp(name, "score_add_100"))
        data->to_add += 100;
}
