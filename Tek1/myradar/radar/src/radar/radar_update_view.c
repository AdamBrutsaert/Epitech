/*
** EPITECH PROJECT, 2022
** radar_update_view.c
** File description:
** radar_update_view.c
*/

#include "radar.h"

void radar_update_view(radar_t *radar)
{
    sfView *view = sfView_create();
    sfVector2u win_size = sfRenderWindow_getSize(radar->window);
    float aspect_ratio = (float)(win_size.x) / (float)(win_size.y);

    sfView_setCenter(view,(sfVector2f){960.0f, 540.0f});
    if (aspect_ratio >= 1920.0f / 1080.0f) {
        sfView_setSize(view,
            (sfVector2f){aspect_ratio * 1080, 1080});
    } else {
        sfView_setSize(view,
            (sfVector2f){1920, 1.0f / aspect_ratio * 1920});
    }
    sfRenderWindow_setView(radar->window, view);
    sfView_destroy(view);
}
