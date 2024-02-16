/*
** EPITECH PROJECT, 2022
** radar_on_event.c
** File description:
** radar_on_event.c
*/

#include "radar.h"

static void toggle_fullscreen(radar_t *radar)
{
    radar->fullscreen = !radar->fullscreen;
    sfRenderWindow_destroy(radar->window);
    radar->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Radar", radar->fullscreen ? sfFullscreen : sfDefaultStyle, NULL);
    radar_update_view(radar);
}

static void toggle_fps_capping(radar_t *radar)
{
    radar->cap_fps = !radar->cap_fps;
    sfRenderWindow_setFramerateLimit(radar->window, radar->cap_fps * 60);
}

void radar_on_event(radar_t *radar, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyL)
            radar->show_hitboxes = !radar->show_hitboxes;
        if (event->key.code == sfKeyS)
            radar->show_sprites = !radar->show_sprites;
        if (event->key.code == sfKeyG)
            radar->show_grid = !radar->show_grid;
        if (event->key.code == sfKeySpace)
            radar->pause = !radar->pause;
        if (event->key.code == sfKeyD)
            radar->show_debug = !radar->show_debug;
        if (event->key.code == sfKeyF11)
            toggle_fullscreen(radar);
        if (event->key.code == sfKeyU)
            toggle_fps_capping(radar);
    }
    if (event->type == sfEvtResized)
        radar_update_view(radar);
}
