/*
** EPITECH PROJECT, 2022
** pea_on_update.c
** File description:
** pea_on_update.c
*/

#include "hunter.h"

void pea_move(scene_t *scene, float dt)
{
    pea_data_t *data = scene->data;
    pea_args_t *args = scene->args;
    sfVector2f *position = &((image_data_t*)data->image->data)->position;

    image_set_position(data->image, position->x + args->direction.x * dt * 750,
        position->y + args->direction.y * dt * 750);
    if (position->x > 864 || position->x < -16 || position->y < -16)
        scene_send_signal(scene, "pea_out_of_map");
}

void pea_animate(scene_t *scene, float dt)
{
    pea_data_t *data = scene->data;
    sfIntRect rect = {0, 0, 16, 16};

    data->elapsed += dt;
    if (data->elapsed >= 0.05f) {
        data->elapsed -= 0.05f;
        data->frame = data->frame + 1;
        if (data->frame == 3)
            scene_send_signal(scene, "pea_destroyed");
        if (data->frame >= 3)
            return;
        rect.left = data->frame * 16;
        image_set_texture_rect(data->image, &rect);
    }
}

void pea_on_update(scene_t *scene, float dt)
{
    pea_data_t *data = scene->data;

    if (!data->destroy) {
        pea_move(scene, dt);
    } else {
        pea_animate(scene, dt);
    }
}
