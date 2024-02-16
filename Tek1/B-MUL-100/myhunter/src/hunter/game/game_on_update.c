/*
** EPITECH PROJECT, 2022
** game_on_update.c
** File description:
** game_on_update.c
*/

#include "hunter.h"

static void process_zombie(scene_t *scene, scene_t *zombie)
{
    game_data_t *data = scene->data;
    pea_vector_t *peas =
        &((peashooter_data_t*)data->peashooter->data)->pea_vector;
    sfFloatRect zombie_hitbox;
    sfFloatRect pea_hitbox;
    sfFloatRect intersection;

    zombie_get_hitbox(zombie, &zombie_hitbox);
    for (uint32_t i = 0; i < peas->length; i++) {
        pea_get_hitbox(peas->peas[i], &pea_hitbox);
        if (sfFloatRect_intersects(&zombie_hitbox, &pea_hitbox,
            &intersection)) {
            scene_send_signal(scene, "score_add_10");
            wave_destroy_zombie(data->wave, zombie);
            peashooter_destroy_pea(data->peashooter, peas->peas[i]);
            break;
        }
    }
}

void game_on_update(scene_t *scene, float dt)
{
    game_data_t *data = scene->data;
    zombie_vector_t *zombies;

    zombies = &((wave_data_t*)data->wave->data)->zombie_vector;
    data->elapsed += dt;
    if (data->elapsed >= 1.0f) {
        data->elapsed -= 1.0f;
        scene_send_signal(scene, "score_add_1");
    }
    for (uint32_t i = zombies->length; i; i--)
        process_zombie(scene, zombies->zombies[i - 1]);
}
