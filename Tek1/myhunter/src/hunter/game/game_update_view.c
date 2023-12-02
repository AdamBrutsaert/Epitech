/*
** EPITECH PROJECT, 2022
** game_update_view.c
** File description:
** game_update_view.c
*/

#include "hunter.h"

void game_update_view(scene_t *scene)
{
    sfView *view = sfView_create();
    game_data_t *data = scene->data;
    sfVector2u win_size = sfRenderWindow_getSize(scene->app->window);
    sfVector2u tex_size = sfTexture_getSize(data->background_texture);
    float aspect_ratio = (float)(win_size.x) / (float)(win_size.y);

    sfView_setCenter(view,(sfVector2f){tex_size.x / 2.0f, tex_size.y / 2.0f});
    if (aspect_ratio >= 864.0f / 512.0f) {
        sfView_setSize(view,
            (sfVector2f){aspect_ratio * tex_size.y, tex_size.y});
    } else {
        sfView_setSize(view,
            (sfVector2f){tex_size.x, 1.0f / aspect_ratio * tex_size.x});
    }
    sfRenderWindow_setView(scene->app->window, view);
    sfView_destroy(view);
}
