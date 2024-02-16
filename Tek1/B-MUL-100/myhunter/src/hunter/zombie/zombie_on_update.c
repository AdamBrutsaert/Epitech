/*
** EPITECH PROJECT, 2022
** zombie_on_update.c
** File description:
** zombie_on_update.c
*/

#include "hunter.h"

static void zombie_handle_moving(scene_t *scene, float dt)
{
    zombie_data_t *data = scene->data;
    zombie_args_t *args = scene->args;
    sfVector2f *position = &((image_data_t*)data->image->data)->position;
    sfIntRect rect = {0,args->side == LEFT ? 57 : 0,35,57};

    position->x += args->side == LEFT ? args->speed * dt : -args->speed * dt;
    image_set_position(data->image, position->x, position->y);
    if ((position->x > 864 && args->side == LEFT)
        || (position->x < -35 && args->side == RIGHT))
        scene_send_signal(scene, "zombie_out_of_map");
    data->elapsed += dt;
    if (data->elapsed >= 0.05f) {
        data->elapsed -= 0.05f;
        data->frame = (data->frame + 1) % 20;
        rect.left = data->frame * 35;
        image_set_texture_rect(data->image, &rect);
    }
}

static void zombie_handle_falling(scene_t *scene, float dt)
{
    zombie_data_t *data = scene->data;
    zombie_args_t *args = scene->args;
    sfVector2f *position = &((image_data_t*)data->image->data)->position;
    sfIntRect rect = {0,114,35,57};

    data->elapsed += dt;
    rect.top += args->side == LEFT ? 57 : 0;
    if (position->y > 512)
        scene_send_signal(scene, "zombie_fell_out_of_map");
    if (data->frame == 3) {
        position->y += data->elapsed * data->elapsed;
        image_set_position(data->image, position->x, position->y);
        return;
    }
    if (data->elapsed >= 0.1f) {
        data->elapsed -= 0.1f;
        data->frame = (data->frame + 1) % 4;
        rect.left = data->frame * 35;
        image_set_texture_rect(data->image, &rect);
    }
}

void zombie_on_update(scene_t *scene, float dt)
{
    zombie_data_t *data = scene->data;

    if (data->animation == ZOMBIE_MOVING_LEFT
        || data->animation == ZOMBIE_MOVING_RIGHT) {
        zombie_handle_moving(scene, dt);
    } else {
        zombie_handle_falling(scene, dt);
    }
}
