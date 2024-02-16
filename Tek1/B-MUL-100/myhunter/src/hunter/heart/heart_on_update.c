/*
** EPITECH PROJECT, 2022
** heart_on_update.c
** File description:
** heart_on_update.c
*/

#include "hunter.h"

static void heart_animate_turn(scene_t *scene)
{
    heart_data_t *data = scene->data;
    sfIntRect rect = {0,0,48,48};

    if (data->elapsed > 0.1f) {
        data->frame = (data->frame + 1) % 8;
        if (data->frame == 0)
            data->ended = 1;
        data->elapsed -= 0.1f;
        rect.left = data->frame * 48;
        image_set_texture_rect(data->image, &rect);
    }
}

static void heart_animate_spawn(scene_t *scene)
{
    heart_data_t *data = scene->data;
    sfIntRect rect = {0,48,48,48};

    if (data->elapsed > 0.1f) {
        data->frame = (data->frame + 1) % 8;
        if (data->frame == 0) {
            data->ended = 1;
            rect.top = 0;
        }
        data->elapsed -= 0.1f;
        rect.left = data->frame * 48;
        image_set_texture_rect(data->image, &rect);
    }
}

static void heart_animate_destroy(scene_t *scene)
{
    heart_data_t *data = scene->data;
    sfIntRect rect = {0,96,48,48};

    if (data->elapsed > 0.1f) {
        data->frame = (data->frame + 1) % 8;
        if (data->frame == 0) {
            data->ended = 1;
            data->frame = 7;
            scene_send_signal(scene, "heart_animation_destroy_finished");
        }
        data->elapsed -= 0.1f;
        rect.left = data->frame * 48;
        image_set_texture_rect(data->image, &rect);
    }
}

static void heart_animate_respawn(scene_t *scene)
{
    heart_data_t *data = scene->data;
    sfIntRect rect = {0,144,48,48};

    if (data->elapsed > 0.1f) {
        data->frame = (data->frame + 1) % 8;
        if (data->frame == 0) {
            data->ended = 1;
            rect.top = 0;
        }
        data->elapsed -= 0.1f;
        rect.left = data->frame * 48;
        image_set_texture_rect(data->image, &rect);
    }
}

void heart_on_update(scene_t *scene, float dt)
{
    heart_data_t *data = scene->data;

    if (data->ended)
        return;
    data->elapsed += dt;
    if (data->animation == HEART_TURN)
        heart_animate_turn(scene);
    if (data->animation == HEART_SPAWN)
        heart_animate_spawn(scene);
    if (data->animation == HEART_DESTROY)
        heart_animate_destroy(scene);
    if (data->animation == HEART_RESPAWN)
        heart_animate_respawn(scene);
}
